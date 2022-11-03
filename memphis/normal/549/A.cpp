#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<cmath>
#include<set>
#include<vector>
//#include<iostream>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int P=1000000007;
const int N=55;

int n,m,cnt;
char s[N][N];
bool e[200];

int main(){
	scanf("%d%d",&n,&m);;
	rep(i,1,n) scanf("%s",s[i]+1);
	rep(i,1,n-1) rep(j,1,m-1){
		e[s[i][j]]=1;
		e[s[i+1][j]]=1;
		e[s[i][j+1]]=1;
		e[s[i+1][j+1]]=1;
		if(e['f']==1 && e['a']==1 && e['c']==1 && e['e']==1) ++cnt;
		e[s[i][j]]=0;
		e[s[i+1][j]]=0;
		e[s[i][j+1]]=0;
		e[s[i+1][j+1]]=0;
	}
	printf("%d\n",cnt);
}