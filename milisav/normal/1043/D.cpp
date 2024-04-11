#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[12][120000];
int c[12][120000];
long long b[120000];
long long s=0;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			scanf("%d",&a[i][j]);
			c[i][a[i][j]]=j;
		}
	}
	b[0]=1;
	long long s=1;
	bool p;
	for(int i=1;i<n;i++) {
		p=true;
		for(int j=1;j<m;j++) {
			if(c[j][a[0][i]]!=c[j][a[0][i-1]]+1) p=false;
		}
		b[i]=1;
		if(p) b[i]+=b[i-1];
		//cout<<b[i]<<endl;
		s+=b[i];
	}
	printf("%lld",s);
	return 0;
}