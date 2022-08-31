#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int a[n];
	LL sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	LL diff = 0;
	for(int i = n-1; i >= 0; i--){
		diff = abs(diff - a[i]);
	}
	LL c = (sum - diff)/2;
	LL d = (sum + diff)/2;
	cout << c << " " << d << endl;
}