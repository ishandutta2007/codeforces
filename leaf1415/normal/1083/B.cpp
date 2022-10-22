#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint n, k;
string s, t;
llint cnt[500005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	cin >> s >> t;
	
	llint com = n;
	for(int i = 0; i < n; i++){
		if(s[i] != t[i]){
			com = i;
			break;
		}
	}
	
	for(int i = com+1; i < n; i++){
		if(s[i] == 'a') cnt[n-i]++;
		if(t[i] == 'b') cnt[n-i]++;
	}
	
	llint ans = 2*n - com, sum = 0;
	if(k == 1){
		cout << n << endl;
		return 0;
	}
	if(k == 2){
		cout << ans << endl;
		return 0;
	}
	k -= 2;
	
	for(int i = n-1; i >= 1; i--){
		llint u = min(cnt[i]+sum, k);
		ans += u*i;
		sum += u;
		k -= u;
		if(k <= 0) break;
	}
	cout << ans << endl;
	
	return 0;
}