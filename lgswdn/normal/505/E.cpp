// LUOGU_RID: 90782352
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+9;

int n,m,k,p,h[N],a[N];

struct bb {
	int id,h,a,day;
	bool operator < (const bb &b) const {return day>b.day;}
};
bool check(int H) {
	priority_queue<bb>q;
	for(int i=1;i<=n;i++) if(H-m*a[i]<h[i]) q.push((bb){i,H,a[i],H/a[i]});
	for(int i=1;i<=m&&!q.empty();i++) {
		for(int j=1;j<=k&&!q.empty();j++) {
			bb u=q.top(); q.pop();
			//cout<<i<<" "<<u.id<<" "<<u.day<<endl;
			if(u.day<i) return 0;	//i<0 
			u.h+=p, u.day=u.h/u.a;	//p 
			//cout<<"	"<<u.h<<" "<<u.h-u.a*m<<endl;
			if(u.h-u.a*m<h[u.id]) q.push(u);	//push 
		}
	}
	return q.empty(); 
}

signed main() {
	scanf("%lld%lld%lld%lld",&n,&m,&k,&p);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&h[i],&a[i]);
	int l=1, r=1, ans=0;
	for(int i=1;i<=n;i++) r=max(r,h[i]+a[i]*m);
	while(l<=r) {
		int mid=(l+r)/2;
		//cout<<"MID"<<mid<<endl;
		if(check(mid)) ans=mid, r=mid-1;
		else l=mid+1;
	}
	printf("%lld",ans);
	return 0;
}