#include<bits/stdc++.h>
using namespace std;
int n;
int a[300000];
int b[300000];
bool try_zero() {
	for(int i=0;i<n;i++) if(b[i]!=0) return false;
	return true;
}
int try_ordered() {
	int t=-1;
	for(int i=0;i<n && t==-1;i++) if(b[i]==1) t=i;
	if(t==-1) return -1;
	for(int i=t+1;i<n;i++) {
		if(b[i]!=b[i-1]+1) return -1;
	}
	int k=b[n-1];
	for(int i=0;i<t;i++) {
		if(b[i]!=0 && b[i]-k<=i+1) return -1; 
	}
	return n-k;
}
bool test(int t) {
	for(int i=t;i<n;i++) {
		if(b[i]!=0 && b[i]<=(i-t+1)) return false;
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int j=0;j<n;j++) scanf("%d",&b[j]);
	if(try_zero()) {
		printf("%d",n);
		return 0;
	}
	int t=try_ordered();
	if(t!=-1) {
		printf("%d",t);
		return 0;
	}
	int l=0;
	int r=n;
	while(l<r) {
		int m=(l+r)>>1;
		if(test(m)) r=m;
		else l=m+1;
	}
	printf("%d",l+n);
	return 0;
}