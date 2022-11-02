#include <bits/stdc++.h>
#define maxn 200005
int n,a[maxn],t,min[maxn],max[maxn],vis[maxn];
char s[maxn];

int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);scanf("%s",s+1);
		int flag=0;
		for (int i=1;i<=n;++i)a[i]=s[i]-'0';
		min[n+1]=100;max[0]=0;
		for (int i=1;i<=n;++i)max[i]=std::max(a[i],max[i-1]);
		for (int i=n;i>=1;i--)min[i]=std::min(a[i],min[i+1]);
		int mn=100;
		for (int i=1;i<=n;++i){
			vis[i]=1;
			if (min[i+1]<a[i]||mn<a[i]){vis[i]=2;mn=std::min(mn,a[i]);}
			if (max[i-1]>a[i]&&(mn<a[i]||min[i+1]<a[i])){printf("-\n");flag=1;break;}
		}if (!flag){
			for (int i=1;i<=n;++i)printf("%d",vis[i]);
			printf("\n");
		}
	}
	return 0;
}