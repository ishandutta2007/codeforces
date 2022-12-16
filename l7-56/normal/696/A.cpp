#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
map <ll, ll> cst;
ll q;

ll dep(ll x){
	ll res = 0;
	while(x) x >>= 1, res++;
	return res; 
}
ll f(ll x){
	if(cst.find(x) == cst.end()) return 0;
	return cst[x];
}

int main(){
	scanf("%lld", &q);
	while(q--){
		ll opt,x,y,w;
		scanf("%lld%lld%lld", &opt, &x, &y);
		if(opt == 1){
			scanf("%lld", &w);
			while(x != y){
				if(dep(x) < dep(y)) swap(x, y);
				cst[x] = f(x) + w; x >>= 1;
			}
		}
		else {
			ll sum = 0;
			while(x != y){
				if(dep(x) < dep(y)) swap(x, y);
				sum += f(x); x >>= 1;
			}
			printf("%lld\n", sum);
		}
	}
	return 0;
}