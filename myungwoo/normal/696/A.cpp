#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

int Q;
map <lld, lld> C;

lld lca(lld a, lld b)
{
	vector <int> p, q;
	for (;a;a>>=1) p.pb(a&1);
	for (;b;b>>=1) q.pb(b&1);
	reverse(all(p)); reverse(all(q));
	lld ret = 0;
	for (int i=0;i<sz(p)&&i<sz(q);i++){
		if (p[i] != q[i]) break;
		ret = (ret<<1) | p[i];
	}
	return ret;
}

int main()
{
	for (scanf("%d", &Q);Q--;){
		int t; lld a, b;
		scanf("%d%lld%lld", &t, &a, &b);
		lld c = lca(a, b);
		if (t == 1){
			int v; scanf("%d", &v);
			for (lld n=a;n!=c;n>>=1) C[n] += v;
			for (lld n=b;n!=c;n>>=1) C[n] += v;
		}else{
			lld ans = 0;
			for (lld n=a;n!=c;n>>=1) if (C.count(n)) ans += C[n];
			for (lld n=b;n!=c;n>>=1) if (C.count(n)) ans += C[n];
			printf("%lld\n", ans);
		}
	}
}