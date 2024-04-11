#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int x[n];
	for(int i =0; i < n; i++){
		cin >> x[i];
	}
	sort(x,x+n);
	cout << x[(n-1)/2] << endl;
}