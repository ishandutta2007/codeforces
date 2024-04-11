#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=2005;
string dig[10]={
	"1110111",
	"0010010",
	"1011101",
	"1011011",
	"0111010",
	"1101011",
	"1101111",
	"1010010",
	"1111111",
	"1111011"
};
inline int tonum(string s){
	int res=0;
	for(int i=0;i<7;i++)
		if(s[i]=='1') res|=1<<i;
	return res;
}
inline int getd(int x){
	int res=0;
	while(x)
		res+=x&1,x>>=1;
	return res;
}
int num[10];
int n,k,a[MAXN];
int f[MAXN][MAXN];
int main(){
	for(int i=0;i<10;i++)
		num[i]=tonum(dig[i]);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++){
		string s;
		cin>>s;
		a[i]=tonum(s);
	}
	memset(f,-1,sizeof(f));
	f[n+1][0]=0;
	for(int i=n;i;i--){
		for(int j=0; j<=k; j++){
			for(int d=0;d<10;d++){
				if((num[d]&a[i])!=a[i]) continue;
				if(getd(num[d]^a[i])>j||f[i+1][j-getd(num[d]^a[i])]==-1) continue;
				f[i][j]=d;
			}
		}
	}
	if(~f[1][k]){
		for(int i=1; i<=n; i++){
			printf("%d",f[i][k]);
			k-=getd(num[f[i][k]]^a[i]);
		}
		puts("");
	}else puts("-1");
	return 0;
}