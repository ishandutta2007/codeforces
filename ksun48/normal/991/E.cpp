#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> freq(10, 0);
LL ans = 0;
vector<int> num(10, 0);
LL fact[20];
void solve(int a){
	if(a == 10){
		if(1){
			LL sum = 0;
			for(int j = 0; j < 10; j++) sum += num[j];
			LL cnt = fact[sum];
			for(int j = 0; j < 10; j++){
				cnt /= fact[num[j]];
			}
			ans += cnt;
		}
		if(num[0] > 0){
			num[0]--;
			LL sum = 0;
			for(int j = 0; j < 10; j++) sum += num[j];
			LL cnt = fact[sum];
			for(int j = 0; j < 10; j++){
				cnt /= fact[num[j]];
			}
			ans -= cnt;
			num[0]++;
		}
	} else {
		if(freq[a] == 0){
			solve(a+1);
		} else {
			for(int r = 1; r <= freq[a]; r++){
				num[a] = r;
				solve(a+1);
			}
		}
	}
}
int main(){
	string g;
	cin >> g;
	for(int i = 0; i < g.size(); i++){
		freq[g[i]-'0']++;
	}
	fact[0] = 1;
	for(LL i = 1; i < 20; i++){
		fact[i] = fact[i-1] * i;
	}
	solve(0);
	cout << ans << endl;
}