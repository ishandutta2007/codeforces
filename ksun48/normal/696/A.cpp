#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	map<LL,LL> c0;
	map<LL,LL> c1;
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++){
		int t = 0;
		scanf("%d", &t);
		LL v, u;
		scanf("%I64d%I64d", &v, &u); 
		if(t == 1){
			LL w;
			scanf("%I64d", &w);
			while(u != v){
				if(v > u) swap(u,v);
				if(u % 2 == 0) c0[u/2] += w;
				if(u % 2 == 1) c1[u/2] += w;
				u/= 2;
			}
		} else {
			LL cost = 0;
			while(u != v){
				if(v > u) swap(u,v);
				if(u % 2 == 0) cost += c0[u/2];
				if(u % 2 == 1) cost += c1[u/2];
				u /= 2;
			}
			printf("%I64d\n", cost);
		}
	}
}