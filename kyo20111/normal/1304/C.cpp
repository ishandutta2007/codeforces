#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct query{
	int t, l, r;
	bool operator < (const query &o) const{
		return t < o.t;
	}
}q[111];
int t, n, m;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d %d %d",&q[i].t,&q[i].l,&q[i].r);
		sort(q+1, q+1+n);

		int fl = 0, u = 0, mn = m, mx = m;
		for(int i=1;i<=n;i++){
			int l = q[i].t - u;
			mx = max(mx, min(q[i].r, mx + l));
			mn = min(mn, max(q[i].l, mn - l));
			if(mx > q[i].r) mx = q[i].r;
			if(mn < q[i].l) mn = q[i].l;


			if(mx < mn || mx < q[i].l || q[i].r < mn){
				fl = 1;
				break;
			}
			u = q[i].t;
		}
		puts(fl?"NO":"YES");
	}
}