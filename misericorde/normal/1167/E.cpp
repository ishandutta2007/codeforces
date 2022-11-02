#include <bits/stdc++.h>
#define maxn 1000005
int n,x,arr[maxn],first[maxn]={0},last[maxn]={0},f[maxn]={0};

int main() {
	scanf("%d%d",&n,&x);
	for (int i=1;i<=n;++i) {
		scanf("%d",&arr[i]);
		if (!first[arr[i]]) first[arr[i]]=i;
		last[arr[i]]=i;
	}std::sort(arr+1,arr+n+1);
	//for (int i=1;i<=x;++i) printf(">%d %d\n",first[i],last[i]);
	int lt=0,p1=0,pr=0;
	for (int i=n-1;i>=1;i--) {
		if (arr[i]!=arr[i+1]&&last[arr[i]]>first[arr[i+1]]) {pr=arr[i];
	//	printf("[%d %d %d]",arr[i],first[arr[i+1]],last[arr[i]]);
	break;}
	}f[x+1]=9999999; 
	for (int i=x;i>pr;i--) {
		f[i]=std::min(f[i+1],first[i]?first[i]:99999999);
	}int ed=pr+1; long long ans=0;
//	printf("%d ",pr);
//	for (int i=1;i<=x;++i) printf("%d ",f[i]);
	int flag=0;
	for (int i=1;i<=x;++i) {
		while (p1+1<=n&&arr[p1+1]<i) {
			if (arr[p1+1]!=arr[p1]&&first[arr[p1+1]]<lt) {flag=1;break;}
			lt=std::max(lt,last[arr[p1+1]]);p1++;
		//	printf(">%d\n",lt);
		}if (flag) break; while (f[ed]<lt&&ed-1<=x||ed<i+1) ed++;
	//	printf("%d %d\n",i,ed);
		ans+=x-ed+2;
	}std::cout<<ans;
	return 0;
}