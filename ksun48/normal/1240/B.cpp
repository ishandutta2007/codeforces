#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
	}
	vector<int> minidx(n, 1e9);
	vector<int> maxidx(n, -1e9);
	for(int i = 0; i < n; i++){
		minidx[a[i]] = min(minidx[a[i]], i);
		maxidx[a[i]] = max(maxidx[a[i]], i);
	}
	int tot = 0;
	int streak = 0;
	int last = -1;

	int best = 0;
	for(int i = 0; i < n; i++){
		if(minidx[i] > maxidx[i]) continue;
		tot++;
		if(streak && maxidx[last] > minidx[i]){
			streak = 0;
		}
		last = i;
		streak++;
		best = max(best, streak);
	}
	cout << tot - best << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q;
	cin >> Q;
	for(int _ = 0; _ < Q; _++) solve();
}