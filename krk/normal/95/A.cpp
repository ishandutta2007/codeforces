#include <iostream>
#include <string>
using namespace std;

const int Maxn = 105;

int n;
string forb[Maxn], s;
char let;
bool chan[Maxn];

bool Lw(char c) { return 'a' <= c && c <= 'z'; }

bool Up(char c) { return 'A' <= c && c <= 'Z'; }

char toUp(char c) { if (Lw(c)) return c - 'a' + 'A'; return c; }

char toLw(char c) { if (Up(c)) return c - 'A' + 'a'; return c; }

bool Eq(char a, char b)
{
     return toLw(a) == toLw(b);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> forb[i];
    cin >> s >> let;
    for (int i = 0; i < s.length(); i++)
       for (int j = 0; j < n; j++) if (i + forb[j].length() <= s.length()) {
           int l = 0;
           while (l < forb[j].length() && Eq(s[i + l], forb[j][l])) l++;
           if (l == forb[j].length())
              for (int l = 0; l < forb[j].length(); l++) chan[i + l] = true;
       }
    for (int i = 0; i < s.length(); i++) if (chan[i]) {
        if (Eq(s[i], let))
           if (Up(s[i]))
              if (toUp(let) != 'A') s[i] = 'A';
              else s[i] = 'B';
           else if (toLw(let) != 'a') s[i] = 'a';
                else s[i] = 'b';
        else if (Up(s[i])) s[i] = toUp(let);
        else s[i] = toLw(let);
    }
    cout << s << endl;
    return 0;
}