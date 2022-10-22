#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n;
string s[Maxn];
int gender;

bool Ends(const string &a, const string &b)
{
     return a.find(b, max(int(a.length()) - int(b.length()), 0)) != string::npos;
}

int getGender(const string &s)
{
    if (Ends(s, "lios") || Ends(s, "etr") || Ends(s, "initis")) return 0;
    if (Ends(s, "liala") || Ends(s, "etra") || Ends(s, "inites")) return 1;
    return 2;
}

int getType(const string &s)
{
    if (Ends(s, "lios") || Ends(s, "liala")) return 0;
    if (Ends(s, "etr") || Ends(s, "etra")) return 1;
    if (Ends(s, "initis") || Ends(s, "inites")) return 2;
    return 3;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    while (cin >> s[n]) n++;
    if (n == 1) {
          if (getType(s[0]) < 3) cout << "YES\n";
          else cout << "NO\n";
          return 0;
    }
    gender = getGender(s[0]);
    if (gender == 2) cout << "NO\n";
    else {
         int i;
         for (i = 1; i < n; i++)
            if (gender != getGender(s[i])) break;
         if (i < n) cout << "NO\n";
         else {
              int noun = -1;
              for (i = 0; i < n; i++)
                 if (getType(s[i]) == 1)
                    if (noun == -1) noun = i;
                    else break;
              if (i < n || noun == -1) cout << "NO\n";
              else {
                   for (i = 0; i < n; i++)
                      if (i < noun && getType(s[i]) != 0 ||
                          i > noun && getType(s[i]) != 2) break;
                   if (i < n) cout << "NO\n";
                   else cout << "YES\n";
              }
         }
    }
    return 0;
}