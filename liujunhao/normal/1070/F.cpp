#include <iostream>
#include <algorithm>
#include <queue>
#include<cstdio>
#define pb push_back
#define MAXN 450000
using namespace std;
int n;
char s[3];
int a;
vector<int>b[4];
long long ans;
int main()
{
    cin>>n;
    int i,j;
    for(i=1;i<=n;i++){
        scanf("%s%d",s,&a);
        int t=((s[0]-'0')<<1)+s[1]-'0';
        b[t].pb(a);
    }
    for(i=0;i<4;i++)
        sort(b[i].begin(),b[i].end());
    for(i=b[1].size()-1,j=b[2].size()-1;min(i,j)>=0;i--,j--){
        ans+=b[1][i]+b[2][j];
        b[1].pop_back();
        b[2].pop_back();
    }
    b[1].insert(b[1].end(),b[2].begin(),b[2].end());
    b[1].insert(b[1].end(),b[0].begin(),b[0].end());
    sort(b[1].begin(),b[1].end());
    for(i=b[1].size()-1,j=b[3].size()-1;min(i,j)>=0;i--,j--)
        ans+=b[1][i]+b[3][j];
    for(;j>=0;j--)
        ans+=b[3][j];

    printf("%lld\n",ans);
}