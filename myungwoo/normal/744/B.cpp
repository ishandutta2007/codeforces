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

int N;
int ans[1000];

vector <int> ask(vector <int> arr)
{
	vector <int> ret(N, 0);
	printf("%d\n", sz(arr));
	for (int t: arr) printf("%d ", t+1); puts("");
	fflush(stdout);
	for (int i=0;i<N;i++) scanf("%d", &ret[i]);
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i=0;i<N;i++) ans[i] = 1e9;
	for (int b=0;(1<<b)<N;b++){
		for (int v=0;v<2;v++){
			vector <int> arr, arr2;
			for (int i=0;i<N;i++){
				if (((i >> b) & 1) == v) arr.pb(i);
				else arr2.pb(i);
			}
			auto ret = ask(arr);
			for (int v: arr2) ans[v] = min(ans[v], ret[v]);
		}
	}
	puts("-1");
	for (int i=0;i<N;i++) printf("%d ", ans[i]); puts("");
	fflush(stdout);
}