#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[600000];
int b[600000];
bool pos(int p) {
	int pm=m-1;
	for(int i=n-1;i>=0;i--) {
		if(a[i]>pm) {
			if(a[i]+p<m) return false;
			if(a[i]+p-m<pm) pm=a[i]+p-m;
		}
		else {
			if(a[i]+p<pm) pm=a[i]+p;
		}
	}
	return true;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int l=0,r=m;
	while(l<r) {
		int p=(l+r)>>1;
		if(pos(p)) r=p;
		else l=p+1;
	}
	printf("%d",l);
	return 0;
}