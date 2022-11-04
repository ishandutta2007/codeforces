#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=2009;
typedef pair<int,int> pii;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int n,d[N],d1[N];
bool vst[N],e[N][N];

void qry(int u) {
	printf("? %d\n",u); fflush(stdout);
	rep(i,1,n) scanf("%d",&d[i]);
}

signed main() {
	n=read();
	printf("? %d\n",1); fflush(stdout);
	rep(i,1,n) d1[i]=read();
	int sumodd=0,sumeve=0;
	rep(j,1,n) {
		if(d1[j]==1) e[1][j]=e[j][1]=1;
	} sumodd++;
	rep(i,1,n) {
		if(d1[i]%2==0) sumeve++;
		else sumodd++;
	}
	if(sumeve<sumodd) {
		rep(i,1,n) if(d1[i]%2==0&&i!=1) {
			qry(i);
			rep(j,1,n) {
				if(d[j]==1) e[i][j]=e[j][i]=1;
			}
		}
	} else {
		rep(i,1,n) if(d1[i]%2==1&&i!=1) {
			qry(i);
			rep(j,1,n) {
				if(d[j]==1) e[i][j]=e[j][i]=1;
			}
		}
	}
	puts("!");
	rep(i,1,n) rep(j,1,i-1) if(e[i][j]) printf("%d %d\n",i,j);
	fflush(stdout);
	return 0;
}