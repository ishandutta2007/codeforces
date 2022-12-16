#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int M=100100;
LL n,m,k;
set<LL> p;
LL d=0;
int main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		LL pp;
		scanf("%lld",&pp);
		p.insert(pp);
	}
	LL op=0;
	while(!p.empty()){
		if((*p.begin())-d>k){
			LL x=((*p.begin())-d-1)/k;
			// op+=x;
			d+=x*k;
		}
		op++;
		LL cnt=0;
		while((*p.begin())-d<=k){
			cnt++;
			p.erase(p.begin());
			if(p.empty())break;
		}
		d+=cnt;
	}
	printf("%lld\n",op);
	return 0;
}