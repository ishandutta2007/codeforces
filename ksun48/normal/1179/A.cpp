#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int z = n + n + n + 5;
	vector<pair<int,int> > ans(z);
	for(int b = 0; b < z; b++){
		int c = b % n;
		int d = (b + 1) % n;
		ans[b] = {a[c], a[d]};
		if(a[c] > a[d]){
			swap(a[c], a[d]);
		}
	}
	for(int i = 0; i < q; i++){
		long long v;
		cin >> v;
		v -= 1;
		if(v >= z){
			v = v % (n-1);
			while(v + n-1 < z){
				v += n-1;
			}
		}
		cout << ans[v].first << " " << ans[v].second << '\n';
	}
}