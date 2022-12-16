#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define F(i) for(int i=0;i<n;i++)
#define Fm(i) for(int i=0;i<m;i++)
typedef long long LL;
typedef long double LD;
const int N=2020;
char ans[N*2];
int n,k;
inline bool in(int x,int y){
	return x>=0&&x<n&&y>=0&&y<n;
}
char a[N][N];
int tag[N][N];
int main(){
	scanf("%d%d",&n,&k);
	F(i)F(j){
		char c;
		while(c=getchar(),!isalpha(c))
			;
		a[i][j]=c;
	}
	for(int i=0;i<=2*n-2;i++){
		char p='z'+1;
		for(int x=min(i,n-1),y=max(i-(n-1),0);
		x>=0&&y<n;x--,y++){
			tag[x][y]=i==0?k:-1;
			if(in(x-1,y)&&tag[x-1][y]!=-1){
				tag[x][y]=max(tag[x][y],tag[x-1][y]);
			}
			if(in(x,y-1)&&tag[x][y-1]!=-1){
				tag[x][y]=max(tag[x][y],tag[x][y-1]);
			}
			if(tag[x][y]>0&&a[x][y]!='a'){
				a[x][y]='a';
				tag[x][y]--;
			}
			if(tag[x][y]!=-1)p=min(p,a[x][y]);
		}
		for(int x=min(i,n-1),y=max(i-(n-1),0);
		x>=0&&y<n;x--,y++){
			if(a[x][y]>p){
				tag[x][y]=-1;
			}
		}
		ans[i]=p;
	}
	ans[2*n-1]='\0';
	printf("%s",ans);
	return 0;
}