#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((idnt)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

int N, L;
int A[51], B[51];

int main()
{
	cin >> N >> L;
	for (int i=1;i<=N;i++) scanf("%d", A+i);
	for (int i=1;i<=N;i++) scanf("%d", B+i);
	for (int i=0;i<L;i++){
		vector <int> a, b;
		for (int k=1;k<=N;k++)
			a.pb(A[k]);
		for (int k=1;k<=N;k++)
			b.pb((i+B[k]) % L);
		sort(all(a)); sort(all(b));
		bool sw = 0;
		for (int k=0;k<N;k++) if (a[k] != b[k]) sw = 1;
		if (!sw){ puts("YES"); return 0; }
	}
	puts("NO");
}