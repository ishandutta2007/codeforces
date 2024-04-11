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

#define MAXN (1<<22)

int n,m,r;
bool h[1<<22],h2[1<<22];

int lw[MAXN],idx[MAXN],qidx,cmp[MAXN];
stack<int> st;
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u);cmp[u]=-2;
	fore(i,0,n)if(!(u&(1<<i))){
		int v=u|(1<<i);
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(h[u]){
		int v=u^((1<<n)-1);
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x;bool asd=false;
		do{
			x=st.top();st.pop();cmp[x]=0;
			asd=asd||h2[x];
		}while(x!=u);
		r+=asd;
	}
}

//#include <sys/resource.h>

int main(){
	//rlimit rl;
	//getrlimit(RLIMIT_STACK,&rl);
	//rl.rlim_cur=1024L*1024L*256L;
	//setrlimit(RLIMIT_STACK,&rl);

	scanf("%d%d",&n,&m);
	while(m--){
		int a;
		scanf("%d",&a);
		h[a^((1<<n)-1)]=true;
		h2[a]=true;
	}
	mset(cmp,-1);
	tjn(0);
	printf("%d\n",r);
	return 0;
}