#include<cstdio>

using namespace std;

int nu[128],c[10]={119,18,93,91,58,107,111,82,127,123};
char ss[11];
int a[2001],f[2002][2001],da[2001][2001];;
int main(){
	for(int i=0;i<128;i++)
		for(int j=0;j<7;j++)
			if(i>>j&1)nu[i]++;
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",ss+1);
		int o=0;
		for(int j=1;j<=7;j++)
			o=o*2+(ss[j]=='1');
		a[i]=o;
	}
	f[n+1][0]=1;
	for(int i=n;i;i--)
		for(int j=0;j<=k;j++)
			for(int w=9;w>=0;w--){
				int z=nu[c[w]]-nu[a[i]];
				if((c[w]&a[i])==a[i]&&j>=z&&f[i+1][j-z]){
					f[i][j]=1;
					da[i][j]=w;
					break;
				}
			}
	if(!f[1][k])printf("-1\n");
	else{
		int ii=1,jj=k;
		while(ii<=n){
			printf("%d",da[ii][jj]);
			jj-=nu[c[da[ii][jj]]]-nu[a[ii]];
			ii++;
		}
		printf("\n");
	}
}