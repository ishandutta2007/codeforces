#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
int p[2000001];
int s;
int a[2000001];
int d;
int n;
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++) {
		a[i]=a[i-1]+a[i];
		if(a[i]>=mod) a[i]-=mod;
	}
	d=0;
	for(int i=0;i<n;i++) {
		d+=a[i];
		if(d>=mod) d-=mod;
		s=(p[i]+d);
		if(s>=mod) s-=mod;
		p[i+1]=p[i]+s;
		if(p[i+1]>=mod) p[i+1]-=mod;
		d-=a[i];
		if(d<0) d+=mod;
		d=d*2;
		if(d>=mod) d-=mod;
		d+=a[i];
		if(d>=mod) d-=mod;
	}
	printf("%d",s);
	return 0;
}