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
int s[100005];
int uf[100005];
vector<pair<int,pair<int,int> > > e;

int find(int x){
	if(uf[x]<0)return x;
	return uf[x]=find(uf[x]);
}

bool join(int x, int y){
	x=find(x);y=find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];
	s[x]+=s[y];
	uf[y]=x;
	return s[x]==k;
}

int main(){
	mset(uf,-1);
	scanf("%d%d%d",&n,&m,&k);
	fore(i,0,k){
		int x;
		scanf("%d",&x);x--;
		s[x]=1;
	}
	fore(i,0,m){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);x--;y--;
		e.pb(mp(c,mp(x,y)));
	}
	sort(e.begin(),e.end());
	for(auto p:e){
		int x=p.snd.fst,y=p.snd.snd;
		if(join(x,y)){
			fore(i,0,k)printf("%d%c",p.fst," \n"[i==k-1]);
			return 0;
		}
	}
	assert(0);
	return 0;
}