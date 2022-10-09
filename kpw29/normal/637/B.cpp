#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 9;

set <string> seti;
string s[MAXN];
char tmp[15];

int main()
{
    int n;
    
    cin>>n;
    
    for(int i = 0; i < n; i++)
      {
          scanf("%s", tmp);
          
          s[i] = tmp;
      }
    
    for(int i = n - 1; i >= 0; i--)
      {
          if(seti.insert(s[i]).second == true)
            {
                for(int j = 0; j < int(s[i].size()); j++)
                  {
                      printf("%c", s[i][j]);
                  }
                
                puts("");
            }
      }
    
    return 0;
}