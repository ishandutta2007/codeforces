#include <iostream>
#include <string>
using namespace std;

const int Maxn = 100005;

int sum[Maxn];
int need;
string s, res;


void tryGet()
{
     if (s.length() % 2) { need = s.length() + 1; return; }
     for (int i = s.length() - 1; i >= 0; i--)
        if (s[i] > '7') sum[i] = -1;
        else if (s[i] == '7')
                if (sum[i + 1] == -1) sum[i] = -1;
                else sum[i] = 1 + sum[i + 1];
        else if (s[i] > '4') sum[i] = 1;
        else if (s[i] == '4')
                if (sum[i + 1] == 0) sum[i] = 0;
                else sum[i] = 1;
        else sum[i] = 0;
     int left4 = s.length() / 2, left7 = s.length() / 2;
     if (sum[0] == -1 || sum[0] > left7) { need = s.length() + 2; return; }
     for (int i = 0; i < s.length(); i++) {
         if (left4 && (s[i] < '4' || s[i] == '4' && sum[i + 1] != -1 && sum[i + 1] <= left7)) {
                   left4--; res += "4";
         }
         else if (left7 && sum[i] != -1 && sum[i] <= left7) {
              left7--; res += "7";
         } else { need = s.length() + 2; res = ""; return; }
         if (res[i] > s[i]) break;
     } 
     while (left4--) res += "4";
     while (left7--) res += "7";
}

int main()
{
    getline(cin, s);
    tryGet();
    if (res == "") {
            for (int i = 0; i < need / 2; i++) res += "4";
            for (int i = 0; i < need / 2; i++) res += "7";
    }
    cout << res << endl;
    return 0;
}