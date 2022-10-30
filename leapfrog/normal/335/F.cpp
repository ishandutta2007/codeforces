//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
struct node{int w,c;}a[500005];int at=0,n,in[500005],pnt,tp[500005],tpt;
priority_queue<int,vector<int>,greater<int> >q;ll rs=0;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(in[i]),rs+=in[i];
	sort(in+1,in+n+1,greater<int>()),a[at=1]=(node){in[1],1};
	for(int i=2;i<=n;i++) if(a[at].w==in[i]) a[at].c++;else a[++at]=(node){in[i],1};
	/*for(int i=1;i<=at;i++)
	{
		while(!q.empty()&&a[i].c) s.insert(($){q.top(),a[i].w}),a[i].c--,q.pop();
		while(a[i].c>1)
		{
			auto it=s.upper_bound(($){114514,a[i].w});
			if(it==s.end()||a[i].w*2<=it->y) break;
			int x=it->x,y=it->y;s.erase(it);
			s.insert(($){x,a[i].w}),s.insert(($){y,a[i].w}),a[i].c-=2;
		}
		while(a[i].c) q.push(a[i].w),a[i].c--;
	}*/
	for(int k=1;k<=at;k++)
	{
		int od=min(pnt-2*(int)q.size(),a[k].c),jc=min(pnt,a[k].c)-od;
		for(int i=1;i<=od;i++) tp[++tpt]=a[k].w;
		for(int i=1;i<=jc;i+=2)
		{
			int x=q.top();q.pop();
			if(x<a[k].w) tp[++tpt]=a[k].w,(i<jc?tp[++tpt]=a[k].w:0);
			else tp[++tpt]=x,(i<jc&&2*a[k].w>x?tp[++tpt]=2*a[k].w-x:0);
		}
		pnt+=a[k].c;while(tpt) q.push(tp[tpt--]);
	}
	while(!q.empty()) rs-=q.top(),q.pop();
	return printf("%lld\n",rs),0;
}