#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int> > a(n);
	vector<int> p1(n), p2(n), p2inv(n);
	for(int i = 0; i < n; i++){
		cin >> p1[i];
		p1[i]--;
	}
	for(int i = 0; i < n; i++){
		cin >> p2[i];
		p2[i]--;
		p2inv[p2[i]] = i;
	}
	int best = -1;
	int ans = 0;
	for(int i = 0; i < n; i++){
		int r = p2inv[p1[i]];
		if(r < best){
			ans++;
		}
		best = max(r, best);
	}	
	cout << ans << '\n';
}