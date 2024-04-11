#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL stuff[5000];
LL sum[10000];
LL c = 0;
int main(){
	LL n;
	cin >> n;
	LL a[n];
	for(LL i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i = 0; i < 5000; i++){
		stuff[i] = 0;
	}
	LL c = 0;
	for(LL i = 0; i < n; i++){
		for(LL j = 0; j < i; j++){
			stuff[a[i]-a[j]]++;
			c++;
		}
	}
	for(int i = 0; i < 10000; i++){
		sum[i] = 0;
	}
	for(int i = 4999; i >= 0; i--){
		sum[i] = stuff[i] + sum[i+1];
	}
	LL ans = 0;
	LL deno = c*c*c;
	for(LL i = 0; i < 5000; i++){
		for(LL j = 0; j < 5000; j++){
			ans += sum[i+j+1]*stuff[i]*stuff[j];
		}
	}
	double zz = ans;
	double zz2 = deno;
	printf("%.10lf\n", zz/zz2);

}