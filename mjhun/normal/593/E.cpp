#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000007
#define N 32
using namespace std;

typedef long long ll;

int n;

void mulmat(int c[][N], int a[][N], int b[][N]){
	int t[N][N];
	memset(t,0,sizeof(t));
	fore(i,0,n)fore(j,0,n)fore(k,0,n)t[i][j]+=(1LL*a[i][k]*b[k][j])%MOD,t[i][j]%=MOD;
	memcpy(c,t,sizeof(t));
}

void powmat(int c[][N], int a[][N], int e){
	int t[N][N],r[N][N];
	memcpy(t,a,sizeof(t));
	memset(r,0,sizeof(r));
	fore(i,0,n)r[i][i]=1;
	while(e){
		if(e&1)mulmat(r,r,t);
		e>>=1;
		mulmat(t,t,t);
	}
	memcpy(c,r,sizeof(r));
}

int x[32][32],ox[32][32],w[32][32],w2[32][32];
int ni,nj,q;

int id(int i, int j){
	if(i<0||j<0||i>=ni||j>=nj)return 31;
	return i*nj+j;
}

int main(){
	scanf("%d%d%d",&ni,&nj,&q);
	n=ni*nj;
	fore(i,0,ni){
		fore(j,0,nj){
			ox[id(i,j)][id(i,j)]=1;
			ox[id(i,j)][id(i+1,j)]=1;
			ox[id(i,j)][id(i-1,j)]=1;
			ox[id(i,j)][id(i,j+1)]=1;
			ox[id(i,j)][id(i,j-1)]=1;
		}
	}
	memcpy(x,ox,sizeof(x));
	fore(i,0,n)w[i][i]=1;
	int t=1;
	while(q--){
		int o,a,b,tt;
		scanf("%d%d%d%d",&o,&a,&b,&tt);a=id(a-1,b-1);if(o==2)tt--;
		powmat(w2,x,tt-t);
		mulmat(w,w,w2);
		if(o==1){
			printf("%d\n",w[0][a]);
		}
		else if(o==2){
			fore(i,0,n)x[i][a]=0;
		}
		else {
			fore(i,0,n)x[i][a]=ox[i][a];
		}
		t=tt;
	}
	return 0;
}