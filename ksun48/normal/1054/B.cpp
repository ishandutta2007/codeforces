#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int curmax = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > curmax){
			cout << i + 1 << endl;
			return 0;
		}
		curmax = max(curmax, a[i] + 1);
	}
	cout << -1 << endl;
}