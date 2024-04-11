#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc secondd
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

#define MAXN 200005

int N;
int A[MAXN], D[MAXN];
int S[MAXN];

int main()
{
	scanf("%d", &N);
	for (int i=1;i<=N;i++){
		scanf("%d%d", A+i, D+i);
		S[i] = S[i-1] + A[i];
	}
	int l = -2e9, u = 2e9;
	for (int i=1;i<=N;i++){
		if (D[i] == 1){
			// x + S[i-1] >= 1900
			l = max(l, 1900 - S[i-1]);
		}
		else{
			// x + S[i-1] <= 1899
			u = min(u, 1899 - S[i-1]);
		}
	}
	if (u == 2e9) puts("Infinity");
	else if (l > u) puts("Impossible");
	else printf("%d\n", u + S[N]);
}