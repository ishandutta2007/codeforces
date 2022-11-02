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

#define MAXN 100005

int N, L, R;
int A[MAXN], B[MAXN], C[MAXN], P[MAXN];
int pos[MAXN];

int main()
{
	scanf("%d%d%d", &N, &L, &R);
	for (int i=1;i<=N;i++) scanf("%d", A+i);
	for (int i=1;i<=N;i++) scanf("%d", P+i), pos[P[i]] = i;
	int lower = -1e9;
	for (int i=1;i<=N;i++){
		int x = pos[i];
		// B[x]-A[x] > lower
		// B[x] >= L
		int v = max(L, lower+A[x]+1);
		if (v > R){ puts("-1"); return 0; }
		B[x] = v;
		lower = B[x] - A[x];
	}
	for (int i=1;i<=N;i++) printf("%d ", B[i]); puts("");
}