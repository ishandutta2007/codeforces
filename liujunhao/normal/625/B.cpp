#include<cstdio>
#include<algorithm>
using namespace std;
#include<cstring>
#define MAXN 100000
#define MAXLEN 30
char a[MAXN+10],b[MAXLEN+10];
int na,nb,f[MAXN+5][2],ed[MAXN+10],cnt;
void read(){
	scanf("%s%s",a+1,b+1);
	na=strlen(a+1),nb=strlen(b+1);
}
void solve(){
	int i,j;
	for(i=1;i<=na;i++)
		if(a[i]==b[1]){
			for(j=1;j<=nb;j++)
				if(a[i+j-1]!=b[j])
					break;
				if(j>nb)
					ed[++cnt]=i+nb-1;
		}
}
void dp(){
	int i,j=1,k;
	memset(f,0x3f,sizeof f);
	f[0][0]=0;
	f[0][1]=1;
	for(i=1;i<=na;i++){
		if(ed[j]==i){
			j++;
			f[i][1]=min(f[i-1][0],f[i-1][1])+1;
			for(k=i-nb+1;k<i;k++)
				f[i][0]=min(f[i][0],f[k][1]);
		}
		else{
			f[i][0]=min(f[i-1][0],f[i-1][1]);
			f[i][1]=f[i][0]+1;
		}
	}
}
int main()
{
	read();
	solve();
	dp();
	printf("%d\n",min(f[na][0],f[na][1]));
}