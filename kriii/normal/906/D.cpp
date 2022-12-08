#include <stdio.h>
#include <vector>
using namespace std;

long long fp(long long a, long long p, long long m)
{
	long long r = 1;
	while (p){
		if (p & 1) r = r * a % m;
		a = a * a % m;
		p /= 2;
	}
	return r;
}

int phi(int x)
{
	int r = x;
	for (int i=2;i*i<=x;i++) if (x % i == 0){
		while (x % i == 0) x /= i;
		r /= i;
		r *= i-1;
	}
	if (x > 1){
		r /= x;
		r *= x-1;
	}
	return r;
}

vector<int> chain;
int N,M,W[100100];

pair<long long, bool> go(int l, int r, int d)
{
	if (l == r || W[l] == 1) return {W[l], W[l] <= 100};
	int m = chain[d];
	if (d + 1 == chain.size()) return {0,0};
	auto p = go(l+1,r,d+1);

	if (p.second){
		long long r = 1; bool sm = 1;
		for (int i=0;i<p.first;i++){
			r *= W[l];
			if (r >= 100) sm = 0;
			if (m > 100) r %= m;
			else{
				if (!sm) r %= m;
			}
		}
		return {r,sm};
	}
	return {fp(W[l],p.first+chain[d+1]*100ll,m), 0};
}

int main()
{
	scanf ("%d %d",&N,&M);
	for (int i=1;i<=N;i++) scanf ("%d",&W[i]);
	while (M > 1){
		chain.push_back(M);
		M = phi(M);
	}
	for (int i=0;i<10;i++) chain.push_back(1);

	int Q; scanf ("%d",&Q); while (Q--){
		int l,r; scanf ("%d %d",&l,&r);
		printf ("%lld\n",go(l,r,0).first % chain[0]);
	}

	return 0;
}