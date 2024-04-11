#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;cin >>t;
	while(t--) {
		int x,n,m;
		cin >> x >>n >>m;
		while(n > 0 && x > (x/2) + 10) x = x/2 + 10,--n;
		if(x <= m * 10) puts("YES");
		else puts("NO");
	}
	return 0;
}