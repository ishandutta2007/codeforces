#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int ans = 0;
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int l[n];
	int r[n];
	l[0] = 1;
	for(int i = 1; i < n; i++){
		l[i] = min(a[i], l[i-1]+1);
	}
	r[n-1] = 1;
	for(int i = n-2; i >= 0; i--){
		r[i] = min(r[i+1]+1, a[i]);
	}
	for(int i = 0; i < n; i++){
		ans = max(ans, min(l[i],r[i]));
	}
	cout << ans << endl;



}