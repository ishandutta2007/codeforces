#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int n,m,k;
int uf[100005];

int find(int x){
	if(uf[x]<0)return x;
	return uf[x]=find(uf[x]);
}

bool join(int x, int y){
	x=find(x);y=find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];
	uf[y]=x;
	return true;
}

int main(){
	mset(uf,-1);
	scanf("%d%d%d",&n,&m,&k);
	int c=n;
	fore(_,0,m){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		c-=join(x,y);
	}
	if(k==1){puts("0");return 0;}
	if(c==1){puts("1");return 0;}
	ll r=1;
	fore(_,0,c-2)r=r*n%k;
	fore(i,0,n)if(uf[i]<0)r=r*-uf[i]%k;
	printf("%lld\n",r);
	return 0;
}