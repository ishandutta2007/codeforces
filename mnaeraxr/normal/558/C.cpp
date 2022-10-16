#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double EPS = 1e-9;
const int MAXN = (int)1e7 + 10;

int V[MAXN];
int R[MAXN];
int l[MAXN];

void solve(int v, int idx){
	for (int cnt = 0; v; v >>= 1, ++cnt){
		for (int i = v, c = 0; i < MAXN && l[i] < idx; i <<= 1, ++c){
			V[i] += cnt + c;
			l[i] = idx;
			R[i]++;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		int v;
		scanf("%d", &v);
		solve(v, i + 1);
	}

	int ans = MAXN;
	for (int i = 0; i < MAXN; ++i){
		if (R[i] == n) ans = min(ans, V[i]);
	}

	printf("%d\n", ans);

	return 0;
}