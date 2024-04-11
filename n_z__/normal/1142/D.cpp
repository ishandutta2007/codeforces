#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[100001][11];
main(){
    string s;
    cin>>s;
    int ans=0;
    s=' '+s;
    for(int x=1;x<s.size();x++)
    {
        for(int y=s[x]-'0'+1;y<=10;y++)
        f[x][((y*(y-1)/2+s[x]-'1')%11+11)%11]+=f[x-1][y];
        if(s[x]>'0')f[x][s[x]-'0']++;
        for(int y=0;y<=10;y++)
        ans+=f[x][y];
    }
    cout<<ans<<endl;
}