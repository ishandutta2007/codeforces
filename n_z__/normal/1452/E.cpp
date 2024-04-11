#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
using namespace std;
pair<int,int>a[100001];
#define l first
#define r second
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,m,k;
	cin>>n>>m>>k;
    for(int x=1;x<=m;x++)
    cin>>a[x].l>>a[x].r,a[x].l--;
    int ans=0;
    for(int x=0;x<=n-k;x++)
    for(int y=x;y<=n-k;y++)
    {
        int nowans=0;
        for(int z=1;z<=m;z++)
        nowans+=max(max(min(a[z].r,x+k)-max(a[z].l,x),min(a[z].r,y+k)-max(a[z].l,y)),0);
        ans=max(ans,nowans);
    }
	cout<<ans<<endl;
}