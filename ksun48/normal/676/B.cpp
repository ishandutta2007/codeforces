#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int stuff[12][12];
	int n, t;
	cin >> n >> t;
	stuff[0][0] += 2048 * t;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			stuff[i][j] = 0;
		}
	}
	stuff[0][0] += 2048 * t;
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(stuff[i][j] >= 2048){
				stuff[i+1][j] += (stuff[i][j] - 2048)/2;
				stuff[i][j+1] += (stuff[i][j] - 2048)/2;
				if(i+j<n) ans++;
			}
		}
	}
	cout << ans << endl;
}