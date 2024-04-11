#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200000];
long long l;
int p;
long long d;
int r=0;
int t;
int main()
{
	scanf("%d %d %lld",&n,&m,&l);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	if(a[0]>l) r++;
	for(int i=1;i<n;i++) {
		if(a[i]>l && a[i-1]<=l) r++;
	}
	while(m--) {
		scanf("%d",&t);
		if(t==0) printf("%d\n",r);
		else {
			scanf("%d %lld",&p,&d);
			p--;
			if(a[p]<=l && a[p]+d>l) {
				r++;
				if((p>0 && a[p-1]>l) || (p<n-1 && a[p+1]>l)) r--;
				if((p>0 && a[p-1]>l) && (p<n-1 && a[p+1]>l)) r--;
			}
			a[p]+=d;
		}
	}
	return 0;
}