#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> A(n);
	vector<int> B(n);
	vector<int> a(n), b(n);
	for(int& x : A) cin >> x;
	for(int& x : B) cin >> x;
	for(int i = 0; i < n; i++) a[i] = b[i] = i;
	sort(a.begin(), a.end(), [&](int x, int y) { return A[x] > A[y]; });
	sort(b.begin(), b.end(), [&](int x, int y) { return B[x] > B[y]; });
	vector<int> freq(n, 0);
	set<int> zeroes;
	string ans(n, '0');
	for(int i = 0; i < n; i++){
		freq[a[i]]++;
		freq[b[i]]--;
		if(freq[a[i]]) zeroes.insert(a[i]);
		if(freq[b[i]]) zeroes.insert(b[i]);
		if(!freq[a[i]]) zeroes.erase(a[i]);
		if(!freq[b[i]]) zeroes.erase(b[i]);
		if(zeroes.empty()){
			for(int j = 0; j <= i; j++) ans[a[j]] = '1';
			break;
		}
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}