#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;

int N, M;
int A[MAXN];
vector <int> pos[MAXN];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i=1;i<=M;i++){
		scanf("%d", A+i);
		pos[A[i]].pb(i);
	}
	lld org = 0;
	for (int i=1;i<M;i++) org += abs(A[i]-A[i+1]);
	lld ans = org;
	for (int i=1;i<=N;i++){
		vector <int> arr;
		for (int j=0;j<sz(pos[i]);j++){
			if (pos[i][j] > 1 && A[pos[i][j]-1] != i)
				arr.pb(A[pos[i][j]-1]);
			if (pos[i][j] < M && A[pos[i][j]+1] != i)
				arr.pb(A[pos[i][j]+1]);
		}
		lld diff = 0;
		for (int t: arr) diff -= abs(t-i);
		sort(all(arr));
		int v = arr[sz(arr)>>1];
		for (int t: arr) diff += abs(t-v);
		ans = min(ans, org+diff);
	}
	printf("%lld\n", ans);
}