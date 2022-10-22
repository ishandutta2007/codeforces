#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t,n,a[N],ans;
int main() {
	scanf("%d",&t);
	while(t--) {
		ans = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n;++i) {
			scanf("%d",a+i);
			if(i != 1 && a[i] < a[i-1]) ans = max(ans,a[i-1] - a[i]),a[i] = a[i-1];
		}
		if(ans == 0) {
			puts("0");
			continue;
		}
		cout << (int)log2(ans) + 1 << endl;
	}
	return 0;
}