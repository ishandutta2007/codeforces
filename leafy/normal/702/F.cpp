#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k;
struct TS{
	int c,q;
	bool operator < (const TS & b) const {
		if(q!=b.q) return q>b.q;
		return c<b.c;
	}
}a[N];
struct Per{
	int b,id;
	bool operator < (const Per & x) const {
		return b<x.b;
	}
	bool operator < (const int x) const {
		return b<x;
	} 
}p[N];
struct node{
	int l,r,del,ans;
};
vector<node> v,t;
int ans[N];
inline void rebuild(){
	for(auto x:v){
		//cout<<x.l<<' '<<x.r<<' '<<x.ans<<' '<<x.del<<endl;
		for(int i=x.l;i<=x.r;i++){
			ans[p[i].id]+=x.ans,p[i].b-=x.del;
		}
	}
	sort(p+1,p+k+1);
	v.clear();
	v.push_back({1,k,0,0});
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].c,&a[i].q);
	scanf("%d",&k);
	for(int i=1;i<=k;i++) scanf("%d",&p[i].b),p[i].id=i;
	sort(a+1,a+n+1);sort(p+1,p+k+1);
	v.push_back({1,k,0,0});
	for(int i=1;i<=n;i++){
		for(auto &x:v){
			if(p[x.l].b-x.del>=a[i].c){
				x.del+=a[i].c;
				x.ans++;
			}else if(p[x.r].b-x.del>=a[i].c){
				int pos=lower_bound(p+x.l,p+x.r+1,a[i].c+x.del)-p;
				t.push_back({pos,x.r,x.del+a[i].c,x.ans+1});
				x.r=pos-1;
			}
		}
		v.insert(v.end(),t.begin(),t.end());
		t.clear();
		if(v.size()>500) rebuild();
	}
	if(v.size()) rebuild();
	for(int i=1;i<=k;i++) printf("%d ",ans[i]);
	return 0;
}