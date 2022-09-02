#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int N;
pii p[200020];

int main() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++) scanf("%d",&p[i].Fi);
	for(int i=1;i<=N;i++) scanf("%d",&p[i].Se);
	sort(p+1, p+1+N);
	ll ans = 0, sum = 0;
	priority_queue <int> pq;
	auto Ins = [&](int x) {
		sum += x;
		pq.push(x);
	};
	auto pop = [&]() {
		int t = pq.top(); pq.pop();
		sum -= t;
	};
	Ins(p[1].Se);
	p[N+1] = pii(2e9, 0);
	for(int i=2;i<=N+1;i++) {
		int d = p[i].Fi - p[i-1].Fi;
		for(int j=0;j<d;j++) {
			if(pq.empty()) break;
			pop();
			ans += sum;
		}
		Ins(p[i].Se);
	}
	printf("%lld\n", ans);
	return 0;
}