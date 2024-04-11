#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
void solve(int k, vector<int>& wgts, int r, int s) {
	if(k < 0 || r > s) return;
	int C = s - r + 1;
	/*cerr << C << " | ";
	for(int f : wgts){
		cerr << f << ' ';
	}
	cerr << '\n';*/
	int r2 = r + wgts[k];
	int s1 = r2 - 1;
	int A = wgts[k];
	int B = C - wgts[k];
	for(int i = r; i <= s1; i++) ans[i][k] = '1';
	for(int i = r2; i <= s; i++) ans[i][k] = '0';
	if(r > s1){
		solve(k-1, wgts, r2, s);
		return;
	}
	if(r2 > s){
		solve(k-1, wgts, r, s1);
		return;
	}
	vector<int> wgts1(wgts.size(), 0);
	vector<int> wgts2(wgts.size(), 0);
	int cnt1 = 0;
	int cnt2 = 0;
	for(int i = 0; i < k; i++){
		if(wgts[i] == 0){
			wgts1[i] = 0;
		} else if(wgts[i] == C){
			wgts1[i] = A;
		} else if(wgts[i] == 1){
			if(cnt1 - A < cnt2 - B){
				wgts1[i] = 1;
			} else {
				wgts1[i] = 0;
			}
		} else if(wgts[i] == C-1){
			if(cnt1 - A < cnt2 - B){
				wgts1[i] = A-1;
			} else {
				wgts1[i] = A;
			}
		} else {
			wgts1[i] = max(1, wgts[i] - (B - 1));
		}
		wgts1[i] = max(wgts1[i], max(0, wgts[i] - B));
		wgts1[i] = min(wgts1[i], min(A, wgts[i]));

		wgts2[i] = wgts[i] - wgts1[i];
		if(wgts1[i] != 0 && wgts1[i] != A) cnt1++;
		if(wgts2[i] != 0 && wgts2[i] != B) cnt2++;
		assert(wgts1[i] <= A && wgts1[i] >= 0);
		assert(wgts2[i] <= B && wgts2[i] >= 0);
	}

	assert(cnt1 >= A-1);
	assert(cnt2 >= B-1);
	solve(k-1, wgts1, r, s1);
	solve(k-1, wgts2, r2, s);
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	ans.assign(n+1, string(n, '.'));

	solve(n-1, a, 0, n);
	cout << ans.size() << '\n';
	for(int i = 0; i <= n; i++){
		cout << ans[i] << '\n';
	}
	cout << flush;
	for(int i = 0; i < n; i++){
		int c = 0;
		for(int j = 0; j <= n; j++) if(ans[j][i] == '1') c++;
		for(int j = 0; j <= n; j++) assert(ans[j][i] != '.');
		assert(c == a[i]);
	}
}