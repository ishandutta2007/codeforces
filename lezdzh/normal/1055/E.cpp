#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,s,k;
int a[1501],aa[1501];
int z[1501],f[1501][1501];
int g[1501];
int st[1501],hz[1502];
int ef(int p){
	int l=1,r=st[0];
	while(l!=r){
		int mid=l+r>>1;
		if(st[mid]<=p)r=mid;
		else l=mid+1;
	}
	return l;
}
bool pd(int w){
	for(int i=1;i<=n;i++)
		z[i]=z[i-1]+(a[i]<=w);
	int ans=0;
	for(int i=1;i<=s;i++){
		st[0]=0;
		for(int j=n;j;j--){
			hz[j]=max(hz[j+1],f[i-1][j]);
			while(st[0]&&f[i-1][st[st[0]]]+z[st[st[0]]-1]<=f[i-1][j]+z[j-1])st[0]--;
			st[++st[0]]=j;
			if(g[j]){
				int c=ef(g[j]);
				f[i][j]=max(f[i-1][st[c]]+z[st[c]-1]-z[j-1],hz[g[j]+1]+z[g[j]]-z[j-1]);
			}
//			printf("%d %d %d\n",i,j,f[i][j]);
			ans=max(ans,f[i][j]);
		}
	}
	return ans>=k;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),
		aa[i]=a[i];
	for(int i=1;i<=m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		g[l]=max(g[l],r);
	}
	sort(aa+1,aa+n+1);
	aa[0]=unique(aa+1,aa+n+1)-aa-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(aa+1,aa+aa[0]+1,a[i])-aa;
	int l=1,r=aa[0]+1;
	while(l!=r){
		int mid=l+r>>1;
		if(pd(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",l==aa[0]+1?-1:aa[l]);
}