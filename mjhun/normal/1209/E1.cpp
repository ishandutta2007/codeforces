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

int a[16][2048];
int n,m;
pair<int,int> w[2048];
int z[16];
int o[16];
int r;

void go(int k){
	if(k==n){
		int s=0;
		fore(i,0,n){
			int mx=-1;
			fore(j,0,n)mx=max(mx,a[(i+o[j])%n][z[j]]);
			s+=mx;
		}
		r=max(r,s);
		return;
	}
	fore(i,0,n){
		o[k]=i;
		go(k+1);
	}
}

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		scanf("%d%d",&n,&m);
		mset(a,0);
		fore(i,0,n)fore(j,0,m)scanf("%d",&a[i][j]);
		m=max(m,n);
		fore(j,0,m){
			int mx=-1;
			fore(i,0,n)mx=max(mx,a[i][j]);
			w[j]=mp(mx,j);
		}
		sort(w,w+m);
		reverse(w,w+m);
		fore(i,0,n)z[i]=w[i].snd;
		r=0;
		go(0);
		printf("%d\n",r);
	}
	return 0;
}