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

int ey[100005],ec[100005];

vector<int> g[100005];
int d[100005],t[100005];
queue<int> q;
int n,m;
vector<int> r;

bool can(int k, bool asd=false){
	mset(d,0);
	fore(i,0,n)for(int t:g[i])if(ec[t]>k){
		d[ey[t]]++;
	}
	fore(i,0,n)if(!d[i])q.push(i);
	fore(_,0,n){
		if(q.empty())return false;
		int x=q.front();q.pop();
		t[x]=_;
		for(int t:g[x])if(ec[t]>k){
			int y=ey[t];
			d[y]--;
			if(!d[y])q.push(y);
		}
	}
	assert(q.empty());
	if(asd){
		fore(i,0,n)for(int _:g[i]){
			int c=ec[_],j=ey[_];
			if(c<=k&&t[i]>t[j])r.pb(_);
		}
	}
	return true;
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,m){
		int x;
		scanf("%d%d%d",&x,ey+i,ec+i);x--;ey[i]--;
		g[x].pb(i);
	}
	int s=0,e=1e9+5;
	while(e-s>1){
		int m=(s+e)/2;
		if(can(m-1))e=m;
		else s=m;
	}
	can(s,true);
	sort(r.begin(),r.end());
	printf("%d %d\n",s,SZ(r));
	fore(i,0,SZ(r))printf("%d%c",r[i]+1," \n"[i==SZ(r)-1]);
	return 0;
}