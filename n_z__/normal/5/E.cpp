#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#if ONLINE_JUDGE==luogu
#pragma GCC optimize(3)
#endif
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000001],b[1000001],cnt[1000001];
stack<int>s;
main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int mxid=0;
	for(int x=1;x<=n;x++)
    {
        cin>>a[x];
        if(a[x]>a[mxid])mxid=x;
    }
	int ans=n-1,m=0;
	for(int x=mxid+1;x<=n;x++)
	b[++m]=a[x];
	for(int x=1;x<=mxid-1;x++)
	b[++m]=a[x];
	int len=0;
	for(int x=1;x<=m;x++)
	{
	    while(!s.empty()&&s.top()<b[x])ans+=cnt[len],s.pop(),len--;
	    if(s.empty()||s.top()!=b[x])s.push(b[x]),len++,cnt[len]=0;
	    ans+=cnt[len];
	    cnt[len]++;
	}
	while(len>1)ans+=cnt[len--]; 
	cout<<ans<<endl;
}