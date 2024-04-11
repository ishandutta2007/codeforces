#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

const int Maxn = 30;

int n;
string dict[Maxn];
map <string, bool> win;
map <string, int> mine, yours;

int Nums(const string &s)
{
    int res = 0;
    for (int i = 0; i < n; i++)
       if (dict[i].find(s) != string::npos) res++;
    return res;
}

int Score(const string &s)
{
    int res = 0, mx = 0;
    for (int i = 0; i < s.length(); i++) {
        res += s[i] - 'a' + 1;
        mx = max(mx, s[i] - 'a' + 1);
    }
    return res * mx + Nums(s);
}

bool Better(bool a, int b, int c, bool aw, int bw, int cw)
{
     if (a != aw) return a > aw;
     if (b != bw) return b > bw;
     return c < cw;
}

void Search(const string &s)
{
     if (win.find(s) == win.end()) {
                     int gain = 0;
                     if (s.length()) gain += Score(s);
                     bool w = false;
                     int m = 0, y = 0;
                     for (char c = 'a'; c <= 'z'; c++) {
                         if (Nums(s + c)) {
                                    Search(s + c);
                                    if (Better(!win[s+c], yours[s+c], mine[s+c], w, m, y)) {
                                                          w = !win[s+c];
                                                          m = yours[s+c];
                                                          y = mine[s+c];
                                    }
                         }
                         if (Nums(c + s)) {
                                    Search(c + s);
                                    if (Better(!win[c+s], yours[c+s], mine[c+s], w, m, y)) {
                                                          w = !win[c+s];
                                                          m = yours[c+s];
                                                          y = mine[c+s];
                                    }
                         }
                     }
                     win[s] = w; mine[s] = m; yours[s] = y + gain;
     }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> dict[i];
    Search("");
    if (win[""]) cout << "First\n";
    else cout << "Second\n";
    cout << mine[""] << " " << yours[""] << endl;
    return 0;
}