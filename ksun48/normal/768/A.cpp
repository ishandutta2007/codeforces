#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d", &n);
	int c = 2e9;
	int b = -1;
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		c = min(c, a[i]);
		b = max(b,a[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > c && a[i] < b) ans++;
	}
	cout << ans << endl;
}