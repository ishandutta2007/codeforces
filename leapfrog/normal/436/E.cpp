//
#include<bits/stdc++.h>
using namespace std;
const int o1=0,o2=1,o3=1,o4=0,o5=2;
typedef pair<long long,int> pi;
typedef priority_queue<pi,vector<pi>,greater<pi> > zkak;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
zkak q1,q2,q3,q4,q5;int n,W,r[300005];long long a[300005],b[300005],res=0;
int main()
{
	read(n),read(W);
	for(int i=1;i<=n;i++) read(a[i]),read(b[i]),q1.push(make_pair(a[i],i)),q4.push(make_pair(b[i],i));
	while(W--)
	{
		while(!q1.empty()&&r[q1.top().second]!=o1) q1.pop();
		while(!q2.empty()&&r[q2.top().second]!=o2) q2.pop();
		while(!q3.empty()&&r[q3.top().second]!=o3) q3.pop();
		while(!q4.empty()&&r[q4.top().second]!=o4) q4.pop();
		while(!q5.empty()&&r[q5.top().second]!=o5) q5.pop();
		long long mn=1e15,op=0,p,q;
		if(!q1.empty()&&mn>q1.top().first) mn=q1.top().first,op=1;
		if(!q2.empty()&&mn>q2.top().first) mn=q2.top().first,op=2;
		if(!q3.empty()&&!q4.empty()&&mn>q3.top().first+q4.top().first) mn=q3.top().first+q4.top().first,op=3;
		if(!q4.empty()&&!q5.empty()&&mn>q4.top().first+q5.top().first) mn=q4.top().first+q5.top().first,op=4;
		res+=mn;if(op>=3) p=q4.top().second;
		if(op==1) p=q1.top().second,r[p]=1,q2.push(make_pair(b[p]-a[p],p)),q3.push(make_pair(-a[p],p));
		if(op==2) p=q2.top().second,r[p]=2,q5.push(make_pair(a[p]-b[p],p));
		if(op==3) q=q3.top().second,r[p]=2,r[q]=0,q5.push(make_pair(a[p]-b[p],p)),q1.push(make_pair(a[q],q)),q4.push(make_pair(b[q],q));
		if(op==4) q=q5.top().second,r[p]=2,r[q]=1,q5.push(make_pair(a[p]-b[p],p)),q2.push(make_pair(b[q]-a[q],q)),q3.push(make_pair(-a[q],q));
	}
	printf("%lld\n",res);
	for(int i=1;i<=n;i++) printf("%d",r[i]);
	return putchar('\n'),0;
}