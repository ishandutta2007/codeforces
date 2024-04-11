#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	int ans = 0;
	string a;
	cin >> n >> a;
	for(int i = 0; i < n; i++){
		if(a[i] == '<'){
			ans++;
		} else {
			break;
		}
	}
	reverse(a.begin(), a.end());
	for(int i = 0; i < n; i++){
		if(a[i] == '>'){
			ans++;
		} else {
			break;
		}
	}
	cout << ans << endl;
	return 0;
}