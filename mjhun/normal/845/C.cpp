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

vector<pair<int,int> > e;
int n;

int main(){
#ifdef DEMETRIO
	freopen("cin","r",stdin);
#endif
	while(scanf("%d",&n)!=EOF){
		fore(i,0,n){
			int l,r;
			scanf("%d%d",&l,&r);
			e.pb(mp(l,-1));
			e.pb(mp(r,1));
		}
		sort(e.begin(),e.end());
		int q=0;
		bool r=true;
		for(auto p:e){
			q-=p.snd;
			if(q>2)r=false;
		}
		puts(r?"YES":"NO");
		puts("");
	}
	return 0;
}