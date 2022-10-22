#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn],b[maxn],s[maxn],fir[maxn],p[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)
			p[i]=lower_bound(b+1,b+1+n,a[i])-b,printf("%d%c",b[p[i]]-a[i],i==n? '\n':' ');
		for(int i=1,j=1;i<=n;i++){
			while(j<=n&&a[j]<=b[i])
				j++;
			s[i]=j-1;
			if(s[i]==i)
				fir[i]=i;
			else fir[i]=0;
		}
		for(int i=n;i>=1;i--)
			if(fir[i]==0)
				fir[i]=fir[i+1];
		for(int i=1;i<=n;i++)
			printf("%d%c",b[fir[p[i]]]-a[i],i==n? '\n':' ');
	}
	return 0;
}