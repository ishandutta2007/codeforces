#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=5009;
int n,m,d[N];
char e[N][N];

int main() {
	n=read();
	rep(i,1,n) scanf("%s",e[i]+1);
	rep(i,1,n) rep(j,1,n) if(e[i][j]=='1'&&((!d[i])||e[d[i]][j]=='0')) d[i]=j;
	rep(i,1,n) rep(j,1,n) if(e[d[i]][j]=='1'&&e[j][i]=='1') return printf("%d %d %d\n",i,d[i],j), 0;
	return puts("-1"), 0;
}