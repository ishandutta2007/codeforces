#include<cstdio>

using namespace std;

int l[1001],r[1001];
int c1[1001],c2[1001],f[1001];
int ff(int u){
	return f[u]==u?u:f[u]=ff(f[u]);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&l[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&r[i]);
	for(int i=1;i<=n;i++){
		if(i-l[i]<=0){
			printf("NO\n");
			return 0;
		}
		for(int j=1;j<i;j++)
			if(c1[j]>=i-l[i])c1[j]++;
		c1[i]=i-l[i];
	}
	for(int i=n;i;i--){
		if(n-i-r[i]+1<=0){
			printf("NO\n");
			return 0;
		}
		for(int j=n;j>i;j--)
			if(c2[j]>=n-i-r[i]+1)c2[j]++;
		c2[i]=n-i-r[i]+1;
	}
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(c1[i]<c1[j]&&c2[i]>c2[j])
				f[ff(i)]=ff(j);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(ff(i)==ff(j)&&(c1[i]>c1[j]||c2[i]<c2[j])){
				printf("NO\n");
				return 0;
			}
	printf("YES\n");
	for(int i=1;i<=n;i++)
		printf("%d%c",c1[ff(i)],i==n?'\n':' ');
	
}