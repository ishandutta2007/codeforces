#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define ll long long
#define pb push_back
int n,m,l,r,L[N],R[N],w[N];
struct Node {int x,w;bool operator < (Node t) const {return x<t.x;}};
set<Node> z;set<Node>::iterator it;vector<Node> vc[N];
ll slv(int x)
{
	int t=1,nw=0;ll cnt=0,s=0,res=0;for(int i=1;i<=n;++i) w[i]=0;
	for(int i=1;i<=n;++i)
	{
		for(auto j:vc[i])
		{if(t<=j.x) nw+=j.w,w[j.x]+=j.w;s+=1ll*min(j.x,t-1)*j.w;}
		while(nw>=x) s+=nw,nw-=w[t++];cnt+=t-1;res+=s;
	}return cnt<m?0:res-(cnt-m)*x;
}
int main()
{
	scanf("%d %d",&n,&m);l=0;r=1e9;z.insert((Node) {(int)1e9,0});
	for(int i=1,lst;i<=n;++i)
	{
		Node t;scanf("%d %d",&L[i],&R[i]);--R[i];
		vc[i].pb((Node) {i,R[i]-L[i]+1});
		it=z.lower_bound((Node) {L[i]-1,0});t=*it;
		if(t.x>=L[i]) z.insert((Node) {L[i]-1,t.w});
		it=z.lower_bound((Node) {R[i],0});t=*it;
		if(t.x>R[i]) z.insert((Node) {R[i],t.w});lst=L[i]-1;
		while(1)
		{
			it=z.lower_bound((Node) {L[i],0});t=*it;if(t.x>R[i]) break;
			if(t.w) vc[i].pb((Node) {t.w,lst-t.x});lst=t.x;z.erase(it);
		}z.insert((Node) {R[i],i});
	}while(l<=r) {int mid=(l+r)/2;if(slv(mid)) l=mid+1;else r=mid-1;}
	printf("%lld\n",slv(r));return 0;
}