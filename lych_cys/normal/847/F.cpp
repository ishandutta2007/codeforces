#include<bits/stdc++.h>
#define N 109
using namespace std;

int m,n,k,cnt,a[N],b[N],c[N],last[N];
bool check3(int x){
	int i,tmp=0;
	memset(b,0,sizeof(b)); memset(last,0,sizeof(last));
	for (i=1; i<=cnt; i++){
		b[a[i]]++; last[a[i]]=i;
	}
	for (i=cnt+1; i<=n; i++){
		b[x]++; last[x]=n;
	}
	if (!b[x]) return 1;
	for (i=1; i<=m; i++) if (i!=x && (b[i]>b[x] || b[i]==b[x] && last[i]<last[x])) tmp++;
	return tmp>=k;
}
bool check1(int x){
	int i; memset(b,0,sizeof(b)); memset(last,0,sizeof(last));
	for (i=1; i<=cnt; i++){
		b[a[i]]++; last[a[i]]=i;
	}
	if (!b[x]) return 0;
	memset(c,60,sizeof(c));
	for (i=1; i<=m; i++) if (i!=x){
		if (b[i]>b[x]) c[i]=0;
		else if (b[i]==b[x]) c[i]=(last[i]<last[x])?0:1;
		else c[i]=b[x]-b[i]+1;
	}
	sort(c+1,c+m+1);
	int tmp=0;
	for (i=1; i<=k; i++){
		tmp+=c[i];
		if (tmp>n-cnt) return 1;
	}
	return 0;
}
int main(){
	scanf("%d%d%d%d",&m,&k,&n,&cnt);
	if (m==1){ puts("1"); return 0; }
	int i;
	for (i=1; i<=cnt; i++) scanf("%d",&a[i]);
	for (i=1; i<=m; i++){
		if (check3(i)){printf("3 "); continue;}
		if (check1(i)){printf("1 "); continue;}
		printf("2 ");
	}
	return 0;
}