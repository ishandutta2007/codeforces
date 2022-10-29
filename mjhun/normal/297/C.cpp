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
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int n;
pair<int,int> x[100005];
int r0[100005],r1[100005];

int main(){
	memset(r0,-1,sizeof(r0));memset(r1,-1,sizeof(r1));
	scanf("%d",&n);
	fore(i,0,n){
		int k;
		scanf("%d",&k);
		x[i]=mp(k,i);
	}
	sort(x,x+n);
	fore(i,0,(n+2)/3)r0[x[i].snd]=i;
	fore(i,(n+2)/3,min((n+2)/3*2,n))r1[x[i].snd]=i;
	fore(i,(n+2)/3*2,n)r1[x[i].snd]=((n+2)/3-1)-(i-(n+2)/3*2);
	fore(_,0,n){
		int s=x[_].fst,i=x[_].snd;
		if(r0[i]<0)r0[i]=s-r1[i];
		if(r1[i]<0)r1[i]=s-r0[i];
	}
	puts("YES");
	fore(i,0,n)printf("%d%c",r0[i]," \n"[i==n-1]);
	fore(i,0,n)printf("%d%c",r1[i]," \n"[i==n-1]);
	return 0;
}