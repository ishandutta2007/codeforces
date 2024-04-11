#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int p[n];
	int b[n];
	for(int i = 0; i < n; i++){
		cin >> p[i];
		p[i]--;

	}
	int r = 0;
	for(int i = 0; i < n; i++){
		int b;
		cin >> b;
		r ^= b;
	}
	r ^= 1;
	int ans = 0;
	int vis[n];
	for(int i = 0; i < n; i++) vis[i] = 0;
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			int c = i;
			while(1){
				vis[c] = 1;
				c = p[c];
				if(c == i){
					ans++;
					break;
				}
			}
		}
	}
	if(ans == 1) ans--;
	cout << ans+r << endl;
}