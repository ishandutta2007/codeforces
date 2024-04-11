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

int n;

int t[1<<23][2],nt;
bool f[1<<23][2];
bool s[1<<23][2];
vector<pair<ll,int> > r;

void add(ll x, int q, bool b){
	int k=0;
	fore(i,0,q){
		int d=(x>>(31-i))&1;
		if(t[k][d]<0)t[k][d]=nt++;
		k=t[k][d];
	}
	f[k][b]=true;
}

void dfs(int k, ll x, int d){
	if(!s[k][0])return;
	if(!s[k][1]){r.pb(mp(x,d));return;}
	if(f[k][0]||f[k][1]){puts("-1");exit(0);}
	if(t[k][0]>=0)dfs(t[k][0],x,d+1);
	if(t[k][1]>=0)dfs(t[k][1],x|(1LL<<(31-d)),d+1);
}


int main(){
	mset(t,-1);nt=1;
	scanf("%d",&n);
	fore(i,0,n){
		int a,b,c,d,w=1,k=32;
		char s[128];
		scanf("%s",s);
		if(s[0]=='-')w=0; // 0->black
		sscanf(s,"%d.%d.%d.%d",&a,&b,&c,&d);
		if(a<0)a*=-1;
		int z=strlen(s);
		if(s[z-2]=='/')k=s[z-1]-'0';
		else if(s[z-3]=='/')k=(s[z-2]-'0')*10+(s[z-1]-'0');
		/*if(getchar()=='/'){
			scanf("%d",&k);
		}*/
		//printf("%d.%d.%d.%d/%d\n",a,b,c,d,k);
		add(1LL*a*256*256*256+b*256*256+c*256+d,k,w);
	}
	for(int i=nt-1;i>=0;--i){
		s[i][0]=f[i][0];s[i][1]=f[i][1];
		if(t[i][0]>=0)s[i][0]|=s[t[i][0]][0],s[i][1]|=s[t[i][0]][1];
		if(t[i][1]>=0)s[i][0]|=s[t[i][1]][0],s[i][1]|=s[t[i][1]][1];
	}
	dfs(0,0,0);
	printf("%d\n",SZ(r));
	for(auto p:r){
		ll x=p.fst;int k=p.snd;
		printf("%lld.%lld.%lld.%lld/%d\n",x/(256*256*256),x/(256*256)%256,x/256%256,x%256,k);
	}
	return 0;
}