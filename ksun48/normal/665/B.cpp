#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	int p[k];
	for(int i = 0; i < k; i++){
		cin >> p[i];
	}
	int ans = 0;
	for(int i = 0; i < m*n; i++){
		int a = 0;
		cin >> a;
		for(int j = 0; j < k; j++){
			if(p[j] == a){
				ans += (j+1);
				for(int c = j; c > 0; c--){
					p[c] = p[c-1];
				}
				p[0] = a;
				break;
			}
		}

	}
	cout << ans << endl;
}