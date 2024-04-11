#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,n) for(int i=1;i<=n;i++)


int N,K,M;
int TN = 1;
vector<ll> cnt, sum;

void init(int X){
	TN = 1; while( TN < X ) TN *= 2;
	cnt.resize(TN*2+10);
	sum.resize(TN*2+10);
}

void update(int pos, ll val){
	int pos0 = pos;
	pos += TN-1;
	cnt[pos] += val;
	sum[pos] += val * pos0;
	for(pos>>=1;pos;pos>>=1){
		cnt[pos] = cnt[pos*2] + cnt[pos*2+1];
		sum[pos] = sum[pos*2] + sum[pos*2+1];
	}
}

pll query(int l, int r){
	pll res = {0,0};
	for(l += TN-1, r += TN-1; l<=r; l>>=1, r>>=1 ){
		if( l&1 ){
			res.Fi += cnt[l]; res.Se += sum[l];
			l++;
		}
		if( !(r&1) ){
			res.Fi += cnt[r]; res.Se += sum[r];
			r--;
		}
	}
	return res;
}

int query_mincost(ll X){
	int cur = 1, L = 1, R = TN;
	while( cur * 2 <= TN*2-1 ){
	//	printf("%d %d %d\n",cur,L,R);
		int lt = cur * 2, rt = cur * 2 + 1;
		if( cnt[lt] >= X ) {
			cur = lt; R = (L+R)/2;
		}
		else{
			cur = rt; X -= cnt[lt];
			L = (L+R)/2+1;
		}
	}
	return R;
}


ll l[1005000], r[1005000], c[1005000], p[1005000];
vector<int> input[1005000], output[1005000];
int main() {
	scanf("%d%d%d",&N,&K,&M);
	init(1e6+10);
	repp(i,M){
		scanf("%lld%lld%lld%lld",l+i,r+i,c+i,p+i);
		input[l[i]].pb(i);
		output[r[i]].pb(i);
	}
	ll ANS = 0;
	for(int i=1;i<=N;i++){
		for(auto e : input[i]){
			update(p[e], c[e]);
	//		printf("update %lld %lld\n",p[e],c[e]);
		}

		if( cnt[1] < K ){
			ANS += sum[1];
		}
		else{
			int R = query_mincost(K);
	//		printf("!%d\n",R);	
			pll res = query(1,R);
			ll diff = res.Fi - K;
			ANS += res.Se - (diff*R);
		}
	//	printf("%lld\n",ANS);

		for(auto e : output[i]){
			update(p[e], -c[e]);
		}
	}

	printf("%lld\n",ANS);
}