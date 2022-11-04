#include <bits/stdc++.h>

using namespace std;

vector<int> c(1e5+5,0);
vector<int> a(1e5+5);
int main(){
	int n,k;

	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		c[a[i]]++;
		if (c[a[i]]==n){
			cout << 0;
			return 0;
		}
	}

	k--;
	for(int i = 0; i < n ; i++){
		c[a[i]]--;
		a[i] = a[k];
		c[a[i]]++;
		k++;
		k %= n;
		if ( c[a[i]] == n ){
			cout << i+1;
			return 0;
		}
	}

	cout << -1;
	return 0;
}