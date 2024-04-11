#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
int n,w,a[MAXN];
double L,R,mid;
int main()
{
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n+n;i++) scanf("%d",&a[i]);
	R=w;
	for(int T=1;T<=100;T++)
	{
		mid=(L+R)/2;
		bool ok=true;
		for(int i=1;i<=n+n;i++)
			if(a[i]<mid) ok=false;
		int cnt=0;
		for(int i=1;i<=n+n;i++)
			if(a[i]>=mid+mid) cnt++;
		if(cnt<n) ok=false;
		if(w<mid*3*n) ok=false;
		if(!ok) R=mid;
		else L=mid;
	}
	printf("%.010lf\n",L*3*n);
	return 0;
}