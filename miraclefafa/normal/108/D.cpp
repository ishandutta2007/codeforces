#include <cstdio>
#include <iostream>
using namespace std;
int n,m,h,i,sum,a[1001];
double s;
int main() {
	cin>>n>>m>>h;
	for (i=1;i<=m;i++) cin>>a[i],sum+=a[i];
	if (sum<n) printf("-1\n"); else {
		s=1;
		for (i=1;i<n;i++) s=s*(sum+1-a[h]-i)/(sum-i);
		printf("%.10f",1-s);
	}
}