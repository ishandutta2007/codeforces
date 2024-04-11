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

int n,m;
int b[128][128];
int sr[128],sc[128];
int rr[128],rc[128];

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)fore(j,0,m)scanf("%d",&b[i][j]),sr[i]+=b[i][j],sc[j]+=b[i][j];
	while(1){
		int k=-1;
		fore(i,0,n)if(sr[i]<0)k=i;
		if(k>=0){
			rr[k]^=1;
			sr[k]*=-1;
			fore(j,0,m)b[k][j]*=-1,sc[j]+=2*b[k][j];
		}
		else {
			fore(j,0,m)if(sc[j]<0)k=j;
			if(k<0)break;
			rc[k]^=1;
			sc[k]*=-1;
			fore(i,0,n)b[i][k]*=-1,sr[i]+=2*b[i][k];
		}
	}
	vector<int> a;
	fore(i,0,n)if(rr[i])a.pb(i);
	printf("%d",SZ(a));
	for(int x:a)printf(" %d",x+1);
	puts("");
	a.clear();
	fore(j,0,m)if(rc[j])a.pb(j);
	printf("%d",SZ(a));
	for(int x:a)printf(" %d",x+1);
	puts("");
	return 0;
}