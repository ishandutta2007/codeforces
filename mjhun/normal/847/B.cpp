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
int x[200005];
set<pair<int,int> > w;
vector<vector<int> > r;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",x+i);
	fore(i,0,n){
		auto it=w.lower_bound(mp(x[i],-1));
		if(it==w.begin()){
			vector<int> a;
			a.pb(x[i]);
			r.pb(a);
			w.insert(mp(x[i],SZ(r)-1));
		}
		else {
			it--;
			int k=it->snd;
			w.erase(it);
			r[k].pb(x[i]);
			w.insert(mp(x[i],k));
		}
	}
	for(auto v:r){
		fore(i,0,v.size()){
			if(i)putchar(' ');
			printf("%d",v[i]);
		}
		puts("");
	}
	return 0;
}