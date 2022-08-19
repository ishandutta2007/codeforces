#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
int n;
double p[1001000],l,ans;
int main() {
	scanf("%d",&n);
	rep(i,n) cin>>p[i];
	l=0;ans=0;
	rep(i,n) l=(l+1)*p[i],ans-=p[i],ans+=2*l;
	printf("%.10f\n",ans);
}