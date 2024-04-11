#include<cstdio>
#include<cstring>
using namespace std;

char a[3001][3002],b[3001][3002];
int z[3001],l[3001],r[3001];
int f[3001];
int fd(char*p,char*q,int w){
	for(int i=2;i<=w;i++){
		int j=f[i-1];
		while(j&&q[j+1]!=q[i])j=f[j];
		f[i]=j+(q[j+1]==q[i]);
	}
	for(int i=1,j=0;p[i];i++){
		while(j&&q[j+1]!=p[i])j=f[j];
		j+=q[j+1]==p[i];
		if(j==w)return i-j+1;
	}
	return 0;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)
		scanf("%s",b[i]+1);
	for(int i=1;i<=n;i++){
		z[i]=strlen(a[i]+1);
		for(int j=1;j<=z[i];j++)
			if(a[i][j]!=b[i][j]){
				if(!l[i])l[i]=j;
				r[i]=j;
			}
	}
	int o=1;
	while(!l[o])o++;
	for(int i=1;i<=n;i++)
		if(l[i]){
			if(r[i]-l[i]+1!=r[o]-l[o]+1){
				printf("NO\n");
				return 0;
			}
			for(int j=0;j<=r[i]-l[i];j++)
				if(a[i][l[i]+j]!=a[o][l[o]+j]||b[i][l[i]+j]!=b[o][l[o]+j]){
					printf("NO\n");
					return 0;
				}
		}
	for(;;){
		for(int i=1;i<=n;i++)
			if(l[i])
				if(l[i]==1||a[i][l[i]-1]!=a[o][l[o]-1]||b[i][l[i]-1]!=b[o][l[o]-1])
					goto ed1;
		for(int i=1;i<=n;i++)
			if(l[i])l[i]--;
	}
	ed1:;
	for(;;){
		for(int i=1;i<=n;i++)
			if(l[i])
				if(r[i]==z[i]||a[i][r[i]+1]!=a[o][r[o]+1]||b[i][r[i]+1]!=b[o][r[o]+1])
					goto ed2;
		for(int i=1;i<=n;i++)
			if(l[i])r[i]++;
	}
	ed2:;
	for(int i=1;i<=n;i++){
		int x=fd(a[i],&a[o][l[o]-1],r[o]-l[o]+1);
		if(x!=l[i]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(int i=l[o];i<=r[o];i++)
		printf("%c",a[o][i]);
	printf("\n");
	for(int i=l[o];i<=r[o];i++)
		printf("%c",b[o][i]);
	printf("\n");
}