#include<iostream>
#define LL long long
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int h[n];
	int v[n];
	for(int i = 0; i < n; i++){
		h[i] = v[i] = 1;
	}
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		h[a] = 0;
		v[b] = 0;
	}
	int ans = 0;
	for(int i = 1; i < n/2; i++){
		ans += h[i]+h[n-i-1]+v[i]+v[n-i-1];
	}
	if(n % 2 == 1){
		if(h[(n-1)/2] + v[(n-1)/2] != 0){
			ans ++;
		}
	}
	cout << ans << endl;
}