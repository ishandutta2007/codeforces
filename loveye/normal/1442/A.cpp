#include<bits/stdc++.h>
using namespace std;
const int N = 30005,INF = 0x3f3f3f3f;
int T,n,a[N],pre[N],suf[N],x[N],y[N];
int main() {
	cin >>T;
	while(T--) {
		cin >>n;
		for(int i = 1;i <= n;++i) cin >>a[i];
		x[1] = a[1],y[1] = 0;
		for(int i = 2;i <= n;++i) {
			if(x[i-1] + y[i-1] > a[i]) x[i] = a[i]-y[i-1],y[i] = y[i-1];
			else y[i] = a[i]-x[i-1],x[i] = x[i-1];
		}
		cout <<(x[n] < 0 ? "NO" :"YES") <<endl;
	}
	return 0;
}