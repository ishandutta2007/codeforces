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
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int n,a,b,r[1<<20];

int main(){
	scanf("%d%d%d",&n,&a,&b);
	int qa=0;
	while(qa*a<=n&&(n-a*qa)%b)qa++;
	if(qa*a>n||(n-a*qa)%b){puts("-1");return 0;}
	int qb=(n-a*qa)/b,c=0;
	fore(i,0,qa){
		fore(j,0,a-1)r[c+j]=c+j+1;
		r[c+a-1]=c;
		c+=a;
	}
	fore(i,0,qb){
		fore(j,0,b-1)r[c+j]=c+j+1;
		r[c+b-1]=c;
		c+=b;
	}
	assert(c==n);
	fore(i,0,n)printf("%d%c",r[i]+1," \n"[i==n-1]);
	return 0;
}