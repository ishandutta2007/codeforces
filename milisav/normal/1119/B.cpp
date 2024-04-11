#include<bits/stdc++.h>
using namespace std;
int n;
int a[2000];
int b[2000];
int h;
bool pos(int t) {
	for(int i=0;i<t;i++) b[i]=a[i];
	sort(b,b+t);
	int ch=h;
	for(int i=t-1;i>=0;i-=2) {
		ch-=b[i];
		if(ch<0) return false;
	}
	return true;
}
int main()
{
	scanf("%d %d",&n,&h);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int l=1;
	int r=n;
	while(l<r) {
		int m=(l+r+1)/2;
		if(pos(m)) l=m;
		else r=m-1;
	}
	printf("%d",l);
	return 0;
}