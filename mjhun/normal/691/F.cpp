#include <bits/stdc++.h>
#define M 3000000
using namespace std;

typedef long long ll;

int n;
int x[M+5];
ll r[M+5];
ll a;

int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d",&n);
	a=1LL*n*(n-1)/2;
	for(int i=0;i<n;++i){
		int w;
		scanf("%d",&w);
		x[w]++;
	}
	for(int i=1;i<=M;++i){
		if(1LL*i*i>M)break;
		r[i*i]+=1LL*x[i]*(x[i]-1)/2;
		for(int j=i+1;1LL*i*j<=M;++j){
			r[i*j]+=1LL*x[i]*x[j];
		}
	}
	for(int i=1;i<=M;++i){
		r[i]+=r[i-1];
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		cout<<2*(a-r[x-1])<<'\n';
	}
	return 0;
}