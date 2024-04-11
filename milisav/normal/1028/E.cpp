#include<bits/stdc++.h>
using namespace std;
int n;
long long b[200000];
long long a[200000];
long long c[200000];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&b[i]);
	for(int i=1;i<n;i++) c[i]=b[i-1];
	c[0]=b[n-1];
	int st=-1;
	bool an=true;
	for(int i=0;i<n;i++) {
		if(b[i]!=0) an=false;
		if(b[i]>c[i]) {
			st=i;
			break;
		}
	}
	if(an) {
		printf("YES\n");
		for(int i=0;i<n;i++) printf("1 ");
		return 0;
	}
	//cout<<st<<endl;
	if(st==-1) {
		printf("NO");
		return 0;
	}
	a[st]=b[st];
	long long x;
	for(int i=st-1;i>=0;i--) {
		x=(c[i]-b[i])/a[i+1]+1;
		a[i]=x*a[i+1]+b[i];
	}
	int j=0;
	for(int i=n-1;i>st;i--) {
		x=(c[i]-b[i])/a[j]+1;
		a[i]=x*a[j]+b[i];
		j--;
		if(j<0) j+=n;
	}
	a[n]=a[0];
	for(int i=0;i<n;i++) {
		if(b[i]!=a[i]%a[i+1]) {
			printf("NO");
			return 0;
		}
	}
	printf("YES\n");
	for(int i=0;i<n;i++) printf("%lld ",a[i]);
	return 0;
}