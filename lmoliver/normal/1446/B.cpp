#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;

template<class T=int>
T read(){
	T x=0;
	char ch=0;
	bool f=false;
	while(!isdigit(ch))f|=(ch=getchar())=='-';
	for(;isdigit(ch);ch=getchar())x=x*10+(ch^'0');
	return f?-x:x;
}

const int N=5050;
char a[N],b[N];
int f[N][N];
int main(){
	int n=read(),m=read();
	ignore=scanf("%s",a);
	ignore=scanf("%s",b);
	//dp[i][j]=max(0,dp[i][j+1]-1,dp[i+1][j]-1,dp[i+1][j+1]+2)
	F(i,0,n)f[i][m]=0;
	F(j,0,m)f[n][j]=0;
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			int &x=f[i][j];
			x=max(0,max(f[i+1][j],f[i][j+1])-1);
			if(a[i]==b[j])x=max(x,f[i+1][j+1]+2);
		}
	}
	int ans=0;
	D(i,n)D(j,m)ans=max(ans,f[i][j]);
	printf("%d\n",ans);
	return 0;
}