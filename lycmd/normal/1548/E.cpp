#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010,INF=0x3f3f3f3f3f3f3f3fll;
int n,m,k,ans,a[N],b[N],c[N],d[N],p[N],q[N],tr[N];
stack<pair<int,int> >s;
void add(int x,int y=1){
	if(x<N)tr[x]+=y,add(x+(x&-x));
}
int ask(int x){
	return x>0?ask(x&(x-1))+tr[x]:0;
}
void init(int n,int*a,int*c){
	for(int i=1;i<=n;i++)
		cin>>a[i],c[i]=INF;
	s=stack<pair<int,int> >();
	for(int i=1;i<=n;i++){
		int t=a[i];
		while(!s.empty()&&a[i]<a[s.top().first])
			t=max(t,s.top().second),s.pop();
		if(!s.empty())
			c[i]=min(c[i],t);
		s.push({i,t});
	}
	s=stack<pair<int,int> >();
	for(int i=n;i;i--){
		int t=a[i];
		while(!s.empty()&&a[i]<=a[s.top().first])
			t=max(t,s.top().second),s.pop();
		if(!s.empty())
			c[i]=min(c[i],t);
		s.push({i,t});
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	init(n,a,c),init(m,b,d);
	iota(p+1,p+1+n,1),iota(q+1,q+1+m,1);
	sort(p+1,p+1+n,[](int x,int y){
		return a[x]<a[y];
	});
	sort(q+1,q+1+m,[](int x,int y){
		return d[x]<d[y];
	});
	for(int i=1,j=m;i<=n;i++){
		while(j&&a[p[i]]+d[q[j]]>k)
			add(b[q[j--]]);
		ans+=ask(k-a[p[i]])-ask(k-c[p[i]]);
	}
	cout<<ans<<"\n";
}