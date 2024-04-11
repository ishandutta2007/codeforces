#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+9;
int T,a[N],c[N];
signed main(){
	cin>>T;
	for(int i=1;i<=T;i++){
		int n; scanf("%lld",&n); 
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		if(n%2==1) printf("%lld ",a[(n+1)/2]);
		for(int i=n/2;i>=1;i--){
			printf("%lld %lld ",a[n-i+1],a[i]);
		}
		printf("\n");
	}
	return 0;
}