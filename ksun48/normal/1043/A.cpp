#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int asum = 0;
	int amax = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		asum += a;
		amax = max(amax, a);
	}
	for(int k = amax; ; k++){
		if(n * k - asum > asum){
			cout << k << endl;
			return 0;
		}
	}
}