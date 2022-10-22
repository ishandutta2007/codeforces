#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int b[200000];
int a[200000];
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	int s=0;
	sort(b,b+n);
	s=b[n-1]-b[0]+1;
	for(int i=1;i<n;i++) a[i-1]=b[i]-b[i-1]-1;
	sort(a,a+n-1);
	//for(int i=0;i<n-1;i++) cout<<a[i]<<" ";
	//cout<<endl;
	for(int i=n-2;i>=n-k && i>=0;i--) s-=a[i];
	printf("%d",s);
	return 0;
}