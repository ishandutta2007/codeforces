#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 1000005;

string s;
int best[Maxn], p[Maxn];
char sgn[Maxn];
int nxtnil[Maxn], nxtone[Maxn];
int start;

int main()
{
    std::ios_base::sync_with_stdio(0);
    getline(cin, s);
    reverse(s.begin(), s.end());
    nxtnil[s.length()] = nxtone[s.length()] = s.length() + 1;
    nxtnil[s.length() - 1] = s.length(); nxtone[s.length() - 1] = s.length() + 1;
    for (int i = int(s.length()) - 2; i >= 0; i--) {
        if (s[i + 1] == '0') nxtnil[i] = i + 1;
        else nxtnil[i] = nxtnil[i + 1];
        if (s[i + 1] == '1') nxtone[i] = i + 1;
        else nxtone[i] = nxtone[i + 1];
    }
    fill(best, best + Maxn, Inf);
    if (s[0] == '1') start = 0;
    else start = nxtone[0];
    best[start] = 0;
    for (int i = 0; i <= s.length(); i++)
        if (best[i] != Inf) {
                    int nxt;
                    // if substract
                    nxt = nxtnil[i];
                    if (i < s.length() && best[i] + 1 < best[nxt]) {
                                best[nxt] = best[i] + 1;
                                p[nxt] = i;
                                sgn[nxt] = '-';
                    }
                    // if add
                    nxt = nxtone[i];
                    if (best[i] + 1 < best[nxt]) {
                                best[nxt] = best[i] + 1;
                                p[nxt] = i;
                                sgn[nxt] = '+';
                    }
        }
    int v = s.length() + 1;
    cout << best[v] << endl;
    while (v != start) {
          cout << sgn[v] << "2^" << p[v] << endl;
          v = p[v];
    }
    return 0;
}