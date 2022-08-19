#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n, m;
	cin >> n >> m;
	vector<LL> freq(m, 0);
	for(LL a = 0; a < m; a++){
		if(a == 0){
			freq[a] = n / m;
		} else {
			freq[a] = (n + m - a) / m;
		}
	}
	LL ans = 0;
	for(LL a = 0; a < m; a++){
		for(LL b = 0; b < m; b++){
			if((a*a + b*b) % m == 0){
				ans += freq[a] * freq[b];
			}
		}
	}
	cout << ans << '\n';
}