#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=100010;
int n,p[MAXN];
string s[MAXN][2],str;
bool ok=true;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) if(s[i][0]>s[i][1]) swap(s[i][0],s[i][1]);
    for(int i=1;i<=n;i++)
    {
        int x=p[i];
        if(s[x][0]>str) str=s[x][0];
        else if(s[x][1]>str) str=s[x][1];
        else {ok=false;break;}
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}