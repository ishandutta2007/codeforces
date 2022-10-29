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

int n,k;
int r[100005];

void doit(int s, int e, int a){
	if(!k||s+1==e){
		fore(i,s,e)r[i]=a+i-s;
		return;
	}
	k-=2;
	int m=(s+e)/2;
	doit(s,m,a+e-m);
	doit(m,e,a);
}

int main(){
	scanf("%d%d",&n,&k);k--;
	if(k%2){puts("-1");return 0;}
	doit(0,n,0);
	if(k){puts("-1");return 0;}
	fore(i,0,n)printf("%d%c",r[i]+1," \n"[i==n-1]);
	return 0;
}