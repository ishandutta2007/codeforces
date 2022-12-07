#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=3000010;
int n,k,a[MAXN],s[MAXN],ans;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),s[a[i]]++;
	for(int i=1;i<=3000000;i++) s[i]+=s[i-1];
	for(int K=1;K<=1000000;K++)
	{
		if(s[K-1]) continue;
		if(k>=K-1) {ans=K;continue;}
		bool ok=true;
		for(int i=K;i<=1000000;i+=K)
			if(s[i+K-1]-s[i+k]) {ok=false;break;}
		if(ok) ans=K;
	}
	printf("%d\n",ans);
	return 0;
}