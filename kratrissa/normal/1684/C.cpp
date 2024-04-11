#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int read(){
	int res=0;char c=getchar();
	while(c<48)c=getchar();
	while(c>=48)res=res*10+c-48,c=getchar();
	return res;
}
int T,n,m,tmp[N];vector<int> a[N];
void solve(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i].resize(m+2);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)a[i][j]=read();
	int p=0,q=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)tmp[j]=a[i][j];
		sort(tmp,tmp+m+1);
		int tp=0,tq=0;
		for(int j=1;j<=m;j++)if(a[i][j]!=tmp[j]){
			if(tp==0)tp=j;
			else if(tq==0)tq=j;
			else{printf("-1\n");return;}
		}
		if(i==1||p==0&&q==0)p=tp,q=tq;
	}
	if(p==0&&q==0)p=q=1;
	for(int i=1;i<=n;i++){
		swap(a[i][p],a[i][q]);
		for(int j=1;j<m;j++)if(a[i][j]>a[i][j+1]){printf("-1\n");return;}
	}
	printf("%d %d\n",p,q);
}
int main(){
	T=read();
	while(T--)solve();
	return 0;
}