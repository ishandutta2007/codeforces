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

int a[1024][1024],n,m;
bool w[1024][1024];
int t[1024],nt;

bool can(int k){
	mset(w,false);
	fore(i,0,n){
		nt=0;
		fore(j,0,m)if(a[i][j]>=k)t[nt++]=j;
		fore(j,0,nt)fore(k,j+1,nt){
			if(w[t[j]][t[k]])return true;
			w[t[j]][t[k]]=true;
		}
	}
	return false;
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)fore(j,0,m)scanf("%d",&a[i][j]);
	int s=0,e=1e9+5;
	while(e-s>1){
		int m=(s+e)/2;
		if(can(m))s=m;
		else e=m;
	}
	printf("%d\n",s);
	return 0;
}