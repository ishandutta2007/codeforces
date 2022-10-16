#include<bits/stdc++.h>
using namespace std;
string s,t;
int f[10001][10001];
main()
{
    cin>>s>>t;
    s=' '+s;
    t=' '+t;
    for(int x=1;x<s.size();x++)f[x][0]=0x3fffffff;
    for(int x=1;x<t.size();x++)f[0][x]=0x3fffffff;
    for(int x=1;x<s.size();x++)
    {
        int q=0,w=0;
        if(s[x]=='.'){
            for(int y=x;y>=1;y--)
            {
                if(s[y]=='.')w++;
                else w--;
                if(!w){q=y;break;}
            }
        }
        for(int y=0;y<t.size();y++)
        {
            f[x][y]=f[x-1][y]+1;
            if(y&&s[x]==t[y])f[x][y]=min(f[x][y],f[x-1][y-1]);
            if(q)f[x][y]=min(f[x][y],f[q-1][y]);
        }
    }
    cout<<f[s.size()-1][t.size()-1]<<endl;
}