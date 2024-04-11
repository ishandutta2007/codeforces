#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL a[3100],b[3100],n;
LL f[3100];

//copied from CF
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i] -= i;
		b[i] = a[i];
	}
	sort(b,b+n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			f[j]+=abs(a[i]-b[j]);
			f[j]= j && f[j-1] < f[j] ? f[j-1]:f[j];
		}
	}
	cout << f[n-1] << endl;
}