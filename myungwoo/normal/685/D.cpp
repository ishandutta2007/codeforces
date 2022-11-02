#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;

int N, K;
int X[MAXN], Y[MAXN]; lld ans[MAXN];
int C[MAXN*3], last_changed[MAXN*3];
vector <int> YY;

struct Z{
	int x, y1, y2, v;
};

int main()
{
	scanf("%d%d", &N, &K);
	for (int i=1;i<=N;i++){
		scanf("%d%d", X+i, Y+i);
		YY.pb(Y[i]); YY.pb(Y[i]+K);
	}
	sort(all(YY)); YY.erase(unique(all(YY)), YY.end());
	vector <Z> arr;
	for (int i=1;i<=N;i++){
		int y1 = lower_bound(all(YY), Y[i]) - YY.begin() + 1;
		int y2 = lower_bound(all(YY), Y[i]+K) - YY.begin() + 1;
		arr.pb({X[i], y1, y2, 1});
		arr.pb({X[i]+K, y1, y2, -1});
	}
	sort(all(arr), [](const Z &a, const Z &b){
		return a.x < b.x;
	});
	for (int i=1;i<=sz(YY);i++) last_changed[i] = -1e9-3;
	for (int i=0;i<sz(arr);i++){
		for (int j=arr[i].y1;j<arr[i].y2;j++){
//			if (last_changed[j] < arr[i].x && C[j] > 0){
//				printf("%d: %d -> %d (%d ~ %d)\n", C[j], last_changed[j], arr[i].x, YY[j-1], YY[j]-1);
//			}
			ans[C[j]] += (lld)(arr[i].x - last_changed[j]) * (YY[j] - YY[j-1]);
			last_changed[j] = arr[i].x;
			C[j] += arr[i].v;
		}
	}
	for (int i=1;i<=N;i++) printf("%lld ", ans[i]); puts("");
}