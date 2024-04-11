#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	LL freq[2][2];
	freq[0][0] = freq[0][1] = freq[1][0] = freq[1][1] = 0;
	for(int i = 0; i < n; i++){
		freq[a[i]-'0'][b[i]-'0']++;
	}
	LL ans = freq[0][0] * freq[1][0] + freq[0][0] * freq[1][1] + freq[0][1] * freq[1][0];
	cout << ans << endl;
}