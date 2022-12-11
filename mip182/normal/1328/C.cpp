#include <bits/stdc++.h>
using namespace std;
int main()
{
      int t;
      cin>>t;
      while (t--)
      {
            int n;
            cin>>n;
            string s;
            cin>>s;
            string x,y;
            bool ok=false;
            for (int i=0;i<n;i++)
            {
                  if (ok)
                  x+='0',y+=s[i];
                  else
                  {
                        if (s[i]=='0')
                              x+='0',y+='0';
                        else
                        {
                           if (s[i]=='1')
                           x+='1',y+='0',ok=true;
                           else
                           {
                                 x+='1',y+='1';
                           }
                              
                        }
                  }
            }
            cout<<x<<'\n'<<y<<'\n';
      }
}