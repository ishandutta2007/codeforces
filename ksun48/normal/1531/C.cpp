#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	if(n == 2){
		cout << -1 << '\n';
		return 0;
	}
	int k = 1;
	while(k*k < n) k++;
	if(n == k*k - 2) k++;
	cout << k << '\n';
	int l = n & 1;
	while((l+2) * (l+2) <= n) l += 2;
	vector<string> a(k, string(k, 'o'));
	int tot = k*k;
	for(int v = l; v < k; v++){
		for(int w = l; w < k; w++){
			tot--;
			a[v][w] = '.';
		}
	}
	for(int w = k-1; w >= 0; w--){
		for(int v = w-1; v >= 0; v--){
			if(a[v][w] == 'o' && tot - 2 >= n){
				tot -= 2;
				a[v][w] = a[w][v] = '.';
			}
		}
	}
	reverse(a.begin(), a.end());
	for(string s : a) cout << s << '\n';
}