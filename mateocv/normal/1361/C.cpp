#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;

const int MAXN=1ll<<21;
// Directed version (uncomment commented code for undirected)
struct edge {
	int y;
	list<edge>::iterator rev;
	edge(int y):y(y){}
};
list<edge> g[MAXN];
void add_edge(int a, int b){
	g[a].push_front(edge(b));auto ia=g[a].begin();
	g[b].push_front(edge(a));auto ib=g[b].begin();
	ia->rev=ib;ib->rev=ia;
}
vector<int> p;
void go(int x){
	while(g[x].size()){
		int y=g[x].front().y;
		g[y].erase(g[x].front().rev);
		g[x].pop_front();
		go(y);
	}
	p.push_back(x);
}
vector<int> get_path(int x){ // get a path that begins in x
 //check that a path exists from x before calling to get_path!
	p.clear();go(x);reverse(p.begin(),p.end());
	return p;
}

/*---------------- Union Find (DSU) ------------------*/
const ll N=MAXN;
int pa[N],sz[N];
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b) {
	int x=find_pa(a),y=find_pa(b);
	if (x!=y) {
		if(sz[x]>=sz[y]) sz[x]+=sz[y],pa[y]=x;
		else sz[y]+=sz[x],pa[x]=y;
	}
}
void dsu_init(ll n){fore(i,0,n)pa[i]=i,sz[i]=1;}

ll cant[MAXN];

int main(){FIN;
	ll n; cin>>n;
	//n=5e5;
	pair<ll,ll> a[n];
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	//fore(i,0,n)a[i].fst=((rand()<<16)+rand())%(MAXN/2),a[i].snd=((rand()<<16)+rand())%(MAXN/2);
	for(ll i=20;i>=0;i--){
		//cout<<i<<endl;
		ll pot=1ll<<i;
		dsu_init(pot);
		//set<ll> st;
		//cout<<"HOLAAAAAAAA"<<endl;
		mset(cant,0);
		fore(j,0,n){
			join(a[j].fst%pot,a[j].snd%pot);
			//st.insert(a[j].fst%pot); st.insert(a[j].snd%pot);
			cant[a[j].fst%pot]++; cant[a[j].snd%pot]++;
		}
		ll br=0,tot=0;
		fore(j,0,pot){
			if(cant[j]&1){
				br++; break;
			}
			tot+=(cant[j]>0);
		}
		if(br)continue;
		if(sz[find_pa(a[0].fst%pot)]!=tot){
			continue;
		}
		vector<ll> res(2*n);
		fore(j,0,n)add_edge(a[j].fst%pot,a[j].snd%pot);
		auto w=get_path(a[0].fst%pot);
		//cout<<SZ(w)<<"\n";
		w.pop_back();
		//for(auto j:w)cout<<j<<" "; cout<<"\n";
		vector<pair<long long,ll>> v;
		fore(j,0,n)v.pb({1ll*MAXN*max(a[j].fst%pot,a[j].snd%pot)+min(a[j].fst%pot,a[j].snd%pot),j});
		sort(ALL(v));
		//for(auto j:v)cout<<j.fst<<" "<<j.snd<<"\n"; cout<<endl;
		vector<pair<long long,ll>> ww;
		fore(j,0,n){
		    ww.pb({1ll*MAXN*max(w[j],w[(j+1)%SZ(w)])+min(w[j],w[(j+1)%SZ(w)]),j});
		}
		sort(ALL(ww));
		//for(auto j:ww)cout<<j.fst<<" "<<j.snd<<"\n"; cout<<endl;
		fore(j,0,n){
		    //assert(v[j].fst==ww[j].fst);
		    if(w[ww[j].snd]==a[v[j].snd].fst%pot){
		        res[2*ww[j].snd]=2*v[j].snd;
		        res[2*ww[j].snd+1]=2*v[j].snd+1;
		    }else{
		        res[2*ww[j].snd+1]=2*v[j].snd;
		        res[2*ww[j].snd]=2*v[j].snd+1;
		    }
		}
		cout<<i<<"\n";
		for(auto i:res)cout<<i+1<<" ";
		cout<<"\n";
		return 0;
	}
	
	return 0;
}