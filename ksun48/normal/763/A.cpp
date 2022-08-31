#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	scanf("%d", &n);
	int e[n];
	int d[n];
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &e[i], &d[i]);
	}
	int c[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
	}
	int ans = 0;
	map<int,int> f;
	for(int i = 0; i < n-1; i++){
		if(c[e[i]-1] != c[d[i]-1]){
			ans++;
			f[e[i]]++;
			f[d[i]]++;
		}
	}
	int ok = 1;
	for(int i = 1; i <= n; i++){
		if(f[i] == ans){
			ok = 0;
			cout << "YES" << endl;
			cout << i << endl;
			return 0;
		}
	}
	if(ok){
		cout << "NO" << endl;
	}
}