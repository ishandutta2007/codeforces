#include <bits/stdc++.h>
#define ll long long
int n,m,N,G[25][100005];
ll a[1<<20]={0},b[1<<20]={0};
char s[100005];

void fwht(ll *a,int flag){
	for(int i=1;i<N;i<<=1)
	for(int j=0,len=i<<1;j<N;j+=len)
	for(int k=0;k<i;++k){
		ll A0=a[j+k],A1=a[j+k+i];
		a[j+k]=A0+A1;a[j+k+i]=A0-A1;
		if (flag==-1){a[j+k]>>=1;a[j+k+i]>>=1;}
	}
}

int main(){
	scanf("%d%d",&n,&m);N=1<<n;
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		for(int j=1;j<=m;++j)G[i][j]=s[j]-'0';
	}for(int i=1;i<=m;++i){
		int s=0;
		for(int j=1;j<=n;++j)s=(s<<1)+G[j][i];
		a[s]++;
	}for(int i=0;i<N;++i){
		int cnt=__builtin_popcount(i);
		b[i]=std::min(cnt,n-cnt);
	}fwht(a,1);fwht(b,1);
	for(int i=0;i<N;++i)b[i]=b[i]*a[i];
	fwht(b,-1);
	int ans=1e9;
	for(int i=0;i<N;++i)ans=std::min(ans,(int)b[i]);
	printf("%d",ans);
	return 0;
}