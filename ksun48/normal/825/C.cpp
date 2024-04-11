#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a,a+n);
	int cur = k;
	int ans = 0;
	for(int i = 0; i < n; i++){
		while(a[i] > 2*cur){
			cur *= 2;
			ans++;
		}
		cur = max(cur, a[i]);
	}
	cout << ans << endl;
}