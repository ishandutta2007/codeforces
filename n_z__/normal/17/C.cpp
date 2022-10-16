#include<bits/stdc++.h>
using namespace std;
const int p=51123987;
int f[152][52][52][52],t[3][152];
main()
{
    int n;
    string s;
    cin>>n>>s;
    s=' '+s;
    for(int x=n;x>=1;x--)
    {
        for(int y=0;y<=2;y++)
        t[y][x]=t[y][x+1];
        t[s[x]-'a'][x]=x;
    }
    f[1][0][0][0]=1;
    int ans=0,c=0;
    for(int l=1;l<=n;l++)
    for(int x=0;x<=(n+2)/3;x++)
    for(int y=0;y<=(n+2)/3;y++)
    for(int z=0;z<=(n+2)/3;z++)
    {
        c=f[l][x][y][z],(f[t[0][l]][x+1][y][z]+=c)%=p,(f[t[1][l]][x][y+1][z]+=c)%=p,(f[t[2][l]][x][y][z+1]+=c)%=p;
        if(x+y+z==n&&abs(x-y)<=1&&abs(y-z)<=1&&abs(z-x)<=1)ans=(ans+c)%p;
    }
    cout<<ans<<endl;
}