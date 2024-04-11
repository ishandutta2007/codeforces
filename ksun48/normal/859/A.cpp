#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int k;
	cin >> k;
	int f[k];
	int maxr = 0;
	for(int i = 0; i < k; i++){
		cin >> f[i];
		maxr = max(maxr, f[i]);
	}
	cout << max(0, maxr-25) << endl;
}