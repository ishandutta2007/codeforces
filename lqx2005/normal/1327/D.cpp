/* **********************************************
Created Time: 2020/3/25 18:08:35
File Name: SegmentTree
*********************************************** */
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Deg fprintf(stderr,"Passing [%s] line %d\n",__FUNCTION__,__LINE__)
typedef long long LL;
const int maxn=210000;
const int inf=1e9+7;
int T;
int n;
int p[maxn];
int c[maxn];
int us[maxn];
vector<int> cir[maxn];
int Ch(vector<int> &seq,int to,int st)
{
	int tot=seq.size();
	for(int i=st;i+to<tot;i+=to) if(c[seq[i]]!=c[seq[i+to]]) return 0;
	return 1;
}
int Che(vector<int> &seq,int to)
{
	for(int i=0;i<to;i++) if(Ch(seq,to,i)) return 1;
	return 0;
}
void ins(int x,int tot)
{
	int now=x;
	while(!us[now])
	{
		us[now]=1;
		cir[tot].push_back(now);
		now=p[now];
	}
	return ;
}
int check(vector<int> &seq)
{
	int tot=seq.size();
	int res=inf;
	for(int i=1;i*i<=tot;i++)
	{
		if(tot%i!=0) continue;
		if(Che(seq,i)) res=min(res,i);
		if(Che(seq,tot/i)) res=min(res,tot/i);
	}
	return res;
}
signed main()
{
	scanf("%lld",&T);
	for(int am=1;am<=T;am++)
	{
		scanf("%lld",&n);
		for(int i=0;i<=n;i++) us[i]=0,cir[i].clear();
		for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
		for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
		int tot=0;
		int ans=inf;
		for(int i=1;i<=n;i++)
		{
			if(us[i]) continue;
			ins(i,++tot);
			ans=min(ans,check(cir[tot]));
		}
		if(ans>=inf) printf("-1\n");
		else printf("%lld\n",ans);
	}
	return 0;
}