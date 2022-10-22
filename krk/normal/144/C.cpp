#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int Maxl = 26;

string s, p;
int freq[Maxl];
int res;

int main()
{
    getline(cin, s); getline(cin, p);
    if (s.length() < p.length()) printf("0\n");
    else {
         for (int i = 0; i < p.length(); i++) {
             freq[p[i] - 'a']++;
             if (s[i] != '?') freq[s[i] - 'a']--;
         }
         int l = 0, r = p.length() - 1;
         while (r < s.length()) {
               int i = 0;
               while (i < Maxl && freq[i] >= 0) i++;
               if (i == Maxl) res++;
               if (s[l] != '?') freq[s[l] - 'a']++;
               l++; r++;
               if (r == s.length()) break;
               if (s[r] != '?') freq[s[r] - 'a']--;
         }
         printf("%d\n", res);
    }
    return 0;
}