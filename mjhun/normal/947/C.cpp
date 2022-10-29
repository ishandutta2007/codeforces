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
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

#define MAXN 9000005

int t[MAXN][2],nt=1;
int s[MAXN];
int n;
int a[300005];

void add(int x){
	int k=0;
	for(int i=29;i>=0;--i){
		s[k]++;
		int d=(x>>i)&1;
		if(!t[k][d])t[k][d]=nt++;
		k=t[k][d];
	}
	s[k]++;
}

int query(int x){
	int k=0,r=0;s[k]--;
	for(int i=29;i>=0;--i){
		int d=(x>>i)&1;
		if(t[k][d]&&s[t[k][d]])k=t[k][d];
		else r|=1<<i,k=t[k][d^1];
		s[k]--;
	}
	return r;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i);
	fore(i,0,n){
		int p;
		scanf("%d",&p);
		add(p);
	}
	fore(i,0,n)printf("%d%c",query(a[i])," \n"[i==n-1]);
	return 0;
}