#include<bits/stdc++.h>
#define N 100005
using namespace std;

int n,m,pt,cnt,lf[N],rg[N],blg[N],a[N],num[N],b[325][N<<1],c[325][N]; map<int,int> mp;
int main(){
	scanf("%d",&n); cnt=(int)sqrt(n);
	int i,j,k,x,y;
	for (i=1; i<=cnt; i++){
		lf[i]=rg[i-1]+1; rg[i]=rg[i-1]+cnt;
	}
	rg[cnt]=n;
	for (i=1; i<=cnt; i++)
		for (j=lf[i]; j<=rg[i]; j++) blg[j]=i;
	for (i=1; i<=n; i++){
		scanf("%d",&num[i]); if (!mp[num[i]]) mp[num[i]]=++pt;
		a[i]=mp[num[i]];
	}
	scanf("%d",&m);
	for (i=1; i<=cnt; i++){
		memcpy(b[i],b[i-1],sizeof(b[i]));
		for (j=lf[i]; j<=rg[i]; j++) b[i][a[j]]++;
		for (j=1; j<=n; j++) c[i][b[i][j]]++;
		for (j=n-1; j; j--) c[i][j]+=c[i][j+1];
	}
	while (m--){
		scanf("%d%d%d",&i,&x,&y);
		if (i==1){
			for (i=blg[y]; i<=cnt; i++) c[i][b[i][a[y]]--]--;
			num[y]=x; if (!mp[x]) mp[x]=++pt; a[y]=mp[x];
			for (i=blg[y]; i<=cnt; i++) c[i][++b[i][a[y]]]++;
		} else if (x==1) printf("%d\n",num[y]); else{
			x&=1;
			for (i=lf[blg[y]],j=b[blg[y]-1][a[y]]; i<=y; i++) j+=(a[i]==a[y]);
			if (x){
				for (i=lf[blg[y]],k=c[x=blg[y]-1][j]; i<=y; i++) k+=((++b[x][a[i]])==j);
				printf("%d\n",k);
				for (i=lf[x+1]; i<=y; i++) b[x][a[i]]--;
			} else printf("%d\n",j);
		}
	}
	return 0;
}