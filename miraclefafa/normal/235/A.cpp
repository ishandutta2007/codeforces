#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
int n;
long long gcd(long long a,long long b) {return b?gcd(b,a%b):a;}
int main() {
	scanf("%d",&n);
	if (n==1) {printf("1\n");return 0;}
	if (n==2) {printf("2\n");return 0;}
	if (n==3) {printf("6\n");return 0;}
	long long ans=0;
	for (int i=n;i>=n-10 && i>0;i--) 
		for (int j=n;j>=n-10 && j>0;j--) 
			for (int k=n;k>=n-10 && k>0;k--) {
				long long p=i/gcd(i,j)*j;
				p=p/gcd(p,k)*k;
				if (p>=ans) ans=p;
			}
	cout<<ans<<endl;
}