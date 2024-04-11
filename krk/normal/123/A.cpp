#include <iostream>
#include <string>
using namespace std;

const int Maxl = 26;

string s;
int cnt[Maxl];
int need;

bool Prime(int x)
{
     if (x == 1) return false;
     if (x == 2) return true;
     if (x % 2 == 0) return false;
     for (int i = 3; i * i <= x; i++)
         if (x % i == 0) return false;
     return true;
}

int main()
{
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) cnt[s[i] - 'a']++;
    for (int i = 1; i <= s.length(); i++)
        if (Prime(i) && 2 * i <= s.length())
           for (int j = i; j <= s.length(); j += i)
               if (s[j - 1] != '0') {
                       s[j - 1] = '0'; need++;
               }
    int ind = 0;
    while (ind < Maxl && cnt[ind] < need) ind++;
    if (ind == Maxl) cout << "NO\n";
    else {
         cout << "YES\n";
         cnt[ind] -= need;
         int cur = 0;
         for (int i = 0; i < s.length(); i++)
             if (s[i] != '0') {
                      while (!cnt[cur]) cur++;
                      s[i] = 'a' + cur; cnt[cur]--;
             } else s[i] = 'a' + ind;
         cout << s << endl;
    }
    return 0;
}