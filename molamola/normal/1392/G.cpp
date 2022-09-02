#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int app(int b, int x, int y) {
	if(x == y) return b;
	int bx = (b >> x) & 1;
	int by = (b >> y) & 1;
	if(bx == by) return b;
	return b ^ (1<<x) ^ (1<<y);
}

int N, M, K;
int Read() {
	char In[22];
	scanf("%s", In);
	int res = 0;
	for(int i=0;i<K;i++) res |= (In[i] - '0') << i;
	return res;
}

int X[1000010], Y[1000010];
int C[1<<20], D[1<<20], TC[1<<20];

int main() {
	scanf("%d%d%d", &N, &M, &K);
	int A = Read(), B = Read();
	for(int i=1;i<=N;i++) {
		scanf("%d%d", X + i, Y + i); --X[i]; --Y[i];
	}
	const int INF = 1e9;
	for(int i=0;i<1<<K;i++) C[i] = -INF, D[i] = INF;
	C[B] = N + 1;
	D[A] = N + 1;
	int perm[22];
	rep(i, K) perm[i] = i;
	for(int i=N;i;i--) {
		swap(perm[X[i]], perm[Y[i]]);
		int ta = 0; rep(j, K) if(1<<j & A) ta |= 1<<perm[j];
		D[ta] = min(D[ta], i);
		int tb = 0; rep(j, K) if(1<<j & B) tb |= 1<<perm[j];
		C[tb] = max(C[tb], i);
	}
	for(int a=K;a>=0;a--) {
		int ok = 0, fi = -1, fj = -1;
		rep(i, 1<<K) if(C[i] - D[i] >= M) {
			ok = 1; fi = D[i], fj = C[i] - 1;
			break;
		}
		if(ok) {
			printf("%d\n%d %d\n", a, fi, fj);
			break;
		}
		rep(i, 1<<K) {
			TC[i] = C[i];
			rep(j, K) TC[i] = max(TC[i], C[i^1<<j]);
		}
		rep(i, 1<<K) C[i] = TC[i];
	}
	return 0;
}