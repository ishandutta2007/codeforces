#include<bits/stdc++.h>
const int N=1000005;
#define lxl long long
using namespace std;

lxl calc(int ds,int w){
	w++;
	int p=ds/w,d=ds%w;
	return 1ll*p*p*(w-d)+1ll*(p+1)*(p+1)*d;
}
struct node{
	int ds,w;
	lxl V;
	lxl v()const{
		return calc(ds,w)-calc(ds,w+1);
	}
	int gett(){
		int l=1,r=ds-w,res=1;
		lxl nw=V;
		lxl p=calc(ds,w);
		if(p-calc(ds,w+2)!=nw<<1)return 1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(p-calc(ds,w+mid)==nw*mid)
				res=mid,l=mid+1;
			else r=mid-1;
		}
		return res; 
	}
	bool operator <(node b)const{
		return V<b.V;
	}
};
priority_queue<node> q; 
int a[N];
int n;
lxl m;
lxl res;

void solve(){
//	freopen("data.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i],res+=1ll*(a[i]-a[i-1])*(a[i]-a[i-1]);
		node x={a[i]-a[i-1],0,0};
		x.V=x.v();
		q.push(x);
	}
	lxl ans=0;cin>>m;
	while(res>m){
		auto x=q.top();q.pop();
		int t=x.gett();
		t=min(t,(int)ceil(1.*(res-m)/x.v()));
		res-=x.v()*t;
		x.w+=t;
		x.V=x.v();
		q.push(x);
		ans+=t;
	}
	cout<<ans<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}