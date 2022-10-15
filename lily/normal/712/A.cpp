#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;
/* Configuration */


#define MAXN 100005

int n;
long long a[MAXN],b[MAXN];

int main() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	b[n]=a[n];
	for (int i=n-1,xx=1;i;i--,xx^=1) {
		b[i]=a[i]+a[i+1];
	}
	for (int i=1;i<=n;i++) cout<<b[i]<<" ";
	cout<<endl;

	return 0;
}