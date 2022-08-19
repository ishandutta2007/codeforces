#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int m;
	cin >> m;
	int ans = 1;
	int cur = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(cur + a <= m){
			cur += a;
		} else {
			cur = a;
			ans++;
		}
	}
	cout << ans << '\n';
}