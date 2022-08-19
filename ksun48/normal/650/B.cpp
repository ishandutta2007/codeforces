#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int stuff[2000000];
int n, a, b, T;
int ans = 0;
void solve(){
	int i = n;
	int j = n;
	int t = T;
	t -= stuff[i];
	while(t >= 0){
		ans = max(ans, j-i+1);
		if(ans >= n) return;
		j++;
		t -= a;
		t -= stuff[j];
	}
	while(i > 0){
		i--;
		t -= 2*a;
		t -= stuff[i];
		while(t < 0){
			t += stuff[j];
			t += a;
			j--;
			if(j < n) return;
		}
		ans = max(ans, j-i+1);
	}
	return;
}
int main(){
	cin >> n >> a >> b >> T;
	string c;
	cin >> c;
	for(int i = 0; i < n; i++){
		if(c[i] == 'w'){
			stuff[i] = b+1;
		} else {
			stuff[i] = 1;
		}
		stuff[i+n] = stuff[i+2*n] = stuff[i];
	}
	solve();
	for(int i = 0; i < n; i++){
		if(c[i] == 'w'){
			stuff[(n-i)%n] = b+1;
		} else {
			stuff[(n-i)%n] = 1;
		}
		stuff[(n-i)%n+n] = stuff[(n-i)%n+2*n] = stuff[(n-i)%n];
	}
	solve();
	cout << min(ans,n) << endl;
}