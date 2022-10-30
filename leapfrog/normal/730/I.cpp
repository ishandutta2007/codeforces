//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
//1. make an Empty to B ( B[i]
//2. make an Empty to A than make this A to B ( A[i]+B[j]-A[j]
typedef pair<int,int> pi;typedef priority_queue<pi> qpi;
int n,p,s,a[3005],b[3005],id[3005];pi w[3005];qpi q1,q2,q3;long long res=0;
inline void ins(int i)
{
	if(id[i]==0) q1.push(make_pair(b[i],i)),q2.push(make_pair(a[i],i));
	else if(id[i]==1) q3.push(make_pair(b[i]-a[i],i));
}
int main()
{
	read(n),read(p),read(s);
	for(int i=1;i<=n;i++) read(a[i]),w[i]=make_pair(a[i],i);
	for(int i=1;i<=n;i++) read(b[i]);
	sort(w+1,w+n+1,greater<pi>());
	for(int i=1;i<=p;i++) res+=w[i].first,id[w[i].second]=1;
	for(int i=1;i<=n;i++) ins(i);
	for(int i=1;i<=s;i++)
	{
		int mx=-1e9,typ=0;
		while(!q1.empty()&&id[q1.top().second]!=0) q1.pop();
		while(!q2.empty()&&id[q2.top().second]!=0) q2.pop();
		while(!q3.empty()&&id[q3.top().second]!=1) q3.pop();
		if(!q1.empty()&&mx<q1.top().first) mx=q1.top().first,typ=1;
		if(!q2.empty()&&!q3.empty()&&mx<q2.top().first+q3.top().first) mx=q2.top().first+q3.top().first,typ=2;
		if(!typ) return puts("ZKAK"),0;else res+=mx;
		if(typ==1) id[q1.top().second]=2,ins(q1.top().second);
		if(typ==2) id[q2.top().second]=1,id[q3.top().second]=2,ins(q2.top().second),ins(q3.top().second);
	}
	printf("%lld\n",res);
	for(int i=1;i<=n;i++) if(id[i]==1) printf("%d ",i);
	putchar('\n');for(int i=1;i<=n;i++) if(id[i]==2) printf("%d ",i);
	return putchar('\n'),0;
}