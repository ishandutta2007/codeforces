#include <iostream>
#include <string>
using namespace std;

const int Maxl = 26;

int k, lft, fil;
string s, tmp;
bool is[Maxl];

int main()
{
    cin >> k >> s;
    int i, j;
    for (i = 0, j = s.length()-1; i <= j; i++, j--)
       if (s[i] != '?' && s[j] != '?' && s[i] != s[j]) break;
       else if (s[i] == '?' && s[j] != '?') s[i] = s[j];
       else if (s[i] != '?' && s[j] == '?') s[j] = s[i];
       else if (s[i] == '?' && s[j] == '?') fil++;
    if (i <= j) {
          cout << "IMPOSSIBLE\n"; return 0;
    }
    for (int i = 0; i < s.length(); i++)
       if (s[i] != '?') is[s[i]-'a'] = true;
    for (int i = 0; i < k; i++) if (!is[i]) lft++;
    if (fil < lft) { cout << "IMPOSSIBLE\n"; return 0; }
    else for (int i = 0; i < k; i++) {
            if (fil >= lft && !is[i]) lft--;
            while (fil > lft) {
                  tmp += char('a' + i);
                  fil--; 
            }
         }
    int pnt = 0;
    for (i = 0, j = s.length()-1; i <= j; i++, j--)
       if (s[i] == '?') s[i] = s[j] = tmp[pnt++];
    cout << s << endl;
    return 0;
}