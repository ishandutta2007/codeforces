#include<bits/stdc++.h>
using namespace std;
long long x[2000000][2];
int p[400000];
int n;
int a[400000];
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		p[i]=p[i-1]^a[i];
	}
	long long cf=0,t;
	for(int i=0;i<=n;i++) {
		cf+=(x[p[i]][i%2]);
		x[p[i]][i%2]++;
	}
	printf("%lld",cf);
	return 0;
}