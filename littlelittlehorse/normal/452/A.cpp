#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

string a[] = {"jolteon", "flareon", "umbreon", "leafeon", "glaceon", "sylveon"};
int n;
string str;

int main(){
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
     cin >> n >> str;
     if (n == 8)
     {
          puts("vaporeon");
          return 0;
     }
     if (n == 6)
     {
          puts("espeon");
          return 0;
     }
     else 
          for (int i = 0; i < 6; i++)
          {
               bool ok = true;
               for (int j = 0; j < 7; j++)
                    if (a[i][j] != str[j] && str[j] != '.') 
                    {
                         ok = false;
                         break;
                    }
               if (ok)
               {
                    cout << a[i] << endl;
                    return 0;
               }
          }
}