#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,to=b;i<to;++i)
#define MOD 1000000007
using namespace std;

typedef long long ll;

void mmul(int r[][2], int x[][2], int y[][2]){
	int t[2][2];
	fore(i,0,2){
		fore(j,0,2){
			t[i][j]=0;
			fore(k,0,2){
				t[i][j]+=(1LL*x[i][k]*y[k][j])%MOD;
				if(t[i][j]>=MOD)t[i][j]-=MOD;
			}
		}
	}
	memcpy(r,t,sizeof(t));
}

int t2[64][2][2];

void mexp(int r[][2], ll e){
	int t[2][2];
	memset(t,0,sizeof(t));
	fore(i,0,2)t[i][i]=1;
	int k=0;
	while(e){
		if(e&1)mmul(t,t,t2[k]);
		e>>=1;k++;
	}
	memcpy(r,t,sizeof(t));
}

int x[2][2];
int yy[2][2];
int y[2];

void doit(ll e, int a, int b){
	mexp(x,e);
	//printf(" %d %d %d %d\n",x[0][0],x[0][1],x[1][0],x[1][1]);
	yy[0][0]=a;
	yy[1][0]=b;
	mmul(yy,x,yy);
	y[0]=yy[0][0];
	y[1]=yy[1][0];
}


int st[1<<20][2][2];
int lazy[1<<20][2][2];
int a[100005];
int n,m;

void st_init(int k, int s, int e){
	lazy[k][0][0]=lazy[k][1][1]=1;
	if(s+1==e){
		doit(a[s]-1,0,1);
		st[k][0][0]=y[0];
		st[k][1][0]=y[1];
	}
	else {
		ll m=(s+e)/2;
		st_init(2*k,s,m);
		st_init(2*k+1,m,e);
		st[k][0][0]=(st[2*k][0][0]+st[2*k+1][0][0])%MOD;
		st[k][1][0]=(st[2*k][1][0]+st[2*k+1][1][0])%MOD;
	}
}

void st_push(int k, int s, int e){
	mmul(st[k],lazy[k],st[k]);
	if(e-s>1){
		mmul(lazy[2*k],lazy[2*k],lazy[k]);
		mmul(lazy[2*k+1],lazy[2*k+1],lazy[k]);
	}
	lazy[k][0][0]=lazy[k][1][1]=1;
	lazy[k][0][1]=lazy[k][1][0]=0;
}

void st_upd(int k, int s, int e, int a, int b, int v[][2]){
	st_push(k,s,e);
	if(e<=a||s>=b)return;
	if(s>=a&&e<=b){
		mmul(lazy[k],lazy[k],v);
		st_push(k,s,e);
	}
	else {
		ll m=(s+e)/2;
		st_upd(2*k,s,m,a,b,v);
		st_upd(2*k+1,m,e,a,b,v);
		st[k][0][0]=(st[2*k][0][0]+st[2*k+1][0][0])%MOD;
		st[k][1][0]=(st[2*k][1][0]+st[2*k+1][1][0])%MOD;
	}
	//cout<<s<<' '<<e<<' '<<st[k][0]<<' '<<st[k][1]<<endl;
}

int st_query(int k, int s, int e, int a, int b){
	if(e<=a||s>=b)return 0;
	st_push(k,s,e);
	if(s>=a&&e<=b){
		return st[k][1][0];
	}
	else {
		ll m=(s+e)/2;
		return (st_query(2*k,s,m,a,b)+st_query(2*k+1,m,e,a,b))%MOD;
	}
}

//int fb[1<<20];
//int fibos[1<<20];


int main(){
//	fibos[0]=0;
//	fibos[1]=1;
//	fore(i,2,1<<20)fibos[i]=(fibos[i-1]+fibos[i-2])%MOD;
	t2[0][0][0]=0;
	t2[0][0][1]=t2[0][1][0]=t2[0][1][1]=1;

	fore(k,1,64)mmul(t2[k],t2[k-1],t2[k-1]);

	scanf("%d%d",&n,&m);
	fore(i,0,n){
		scanf("%d",a+i);
	}
	st_init(1,0,n);
	while(m--){
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);l--;
		if(t==1){
			int e;
			scanf("%d",&e);
			mexp(x,e);
			st_upd(1,0,n,l,r,x);
//			fore(i,l,r)fb[i]+=x;
		}
		else {
			printf("%d\n",st_query(1,0,n,l,r));
//			ll q=0;
//			fore(i,l,r)q+=fibos[fb[i]],q%=MOD;
//			cout<<q<<endl;
			//printf("%d\n",st_query(1,0,n,l,r));
		}
	}
	return 0;
}