#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n, b, d, cur = 0, c, ans = 0;
	cin >> n >> b >> d;
	for(int i = 0; i < n; i++){
		cin >> c;
		if(c <= b) cur += c;
		if(cur > d){
			cur = 0;
			ans++;
		}
	}
	cout << ans << endl;
}