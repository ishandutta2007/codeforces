#include<bits/stdc++.h>
using namespace std;
#define int long long
int c[501][501],d[501][501];
string s[501];
main(){
    int n,m;
    cin>>n>>m;
    for(int x=1;x<=n;x++)cin>>s[x],s[x]=' '+s[x];
    int ans=0;
    for(int x=n;x>=1;x--)
    for(int y=m;y>=1;y--)
    {
        if(c[x][y]^(s[x][y]=='B'))ans++,c[x][y]^=1,d[x][y]=1;
        if(c[x][y])c[x-1][y]^=1,c[x][y-1]^=1,c[x-1][y-1]^=1;
    }
    for(int x=1;x<n;x++)
    for(int y=1;y<m;y++)
    if(d[x][y]&&d[x][m]&&d[n][y]&&d[n][m]){cout<<ans-1<<endl;return 0;}
    cout<<ans<<endl;
}
/*
1 2 3 4 5 6
*/