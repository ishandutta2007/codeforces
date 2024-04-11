#include <iostream>
#include <iomanip>
#include <cstdio>

#include <cstring>
#include <string>
#include <sstream>

#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>

#include <queue>
#include <utility>
#include <set>
#include <stack>
#include <vector>
#include <map>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define REPP(i,a,b,d) for(int i=a;i<=b;i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a;i>=b;i-=d)
#define REV(i,a,b) REVV(i,a,b,1)

#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=(int)a-1; i>=0; i--)

#define mp make_pair

#define pb push_back
#define ff first
#define ss second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

#define getc getchar
template<typename T>
T getnum(){
	int sign = 1;
	T ret = 0;
	char c;
	
	do{
		c = getc();
	}while(c == ' ' || c == '\n');
	if(c == '-')sign = -1;
	else ret = c-'0';
	while(1){
		c = getc();
		if(c < '0' || c > '9')break;
		ret = 10*ret + c-'0';
	}
	return sign * ret;
}

inline void ini(int& x){
	x = getnum<int>();
}

inline void scani(int& x){
	scanf("%d",&x);
}

//end of macro

const int N = 1e5 + 5;
const int LOG = 27;

int n,m;
vector<pair<int,pii> >lst[N];
bool used_edge[N];

vector<pair<pii,int> >edges;

bool vis[N];
int d[N];
void dfs(int now){
	FOR(i,lst[now].size()){
		int to = lst[now][i].ff;
		int w = lst[now][i].ss.ff;
		int e = lst[now][i].ss.ss;
		
		if(vis[to]){
			if(!used_edge[e]){
				used_edge[e] = true;
				edges.pb(mp(mp(now,to), w));
			}
		}else{
			used_edge[e] = true;
			d[to] = d[now] ^ w;
			vis[to] = true;
			dfs(to);
		}
	}
}

vi tvec,vec;

int gausscek(int x){
	bool use[35];
	memset(use, false, sizeof use);
	
	tvec = vec;
	
	REV(i,LOG,0){
		int mask = 1<<i;
		bool on = x & mask;
		
		int killer = -1;
		FOR(j,vec.size()){
			if(vec[j] & mask){
				if(!use[j]){
					killer = j;
				}
			}
		}
		
		if(killer != -1){
			use[killer] = true;
			FOR(j,vec.size()){
				if(j == killer)continue;
				if(vec[j] & mask){
					vec[j] ^= vec[killer];
				}
			}
			
			if(!on){
				/*int change = -1;
				FOR(j,vec.size()){
					if(j != killer && use[j]){
						change = j;
					}
				}
				
				if(change == -1){ // no possible candidate, find an unused one
					FOR(j,vec.size()){
						if(j != killer){
							use[j] = true;
							vec[j] ^= vec[killer];
							break;
						}
					} // notice that there is a possibility that at this point, no one is found. therefore, the bit stays on
				}else{
					vec[change] ^= vec[killer];
				}*/
				vec[killer] = 0; // delete killer
			}
		}
	}
	
	FOR(j,vec.size()){
		x ^= vec[j];
	}
	
	vec = tvec;
	
	return x;
}

int insert(int x){
	if(gausscek(x)){
		vec.pb(x);
		//printf("insert %d\n",x);
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    /*vec.pb(9);
    vec.pb(11);
    vec.pb(5);
    while(1){
    	int c;
    	cin>>c;
    	cout<<gausscek(c)<<endl;
	}*/
    
    cin>>n>>m;
    REP(i,1,m){
    	int a,b,c;
    	cin>>a>>b>>c;
    	lst[a].pb(mp(b,mp(c,i)));
    	lst[b].pb(mp(a,mp(c,i)));
	}
	
	vis[1] = true;
	d[1] = 0;
	dfs(1);
	
	FOR(i,edges.size()){
		int a = edges[i].ff.ff;
		int b = edges[i].ff.ss;
		int w = edges[i].ss ^ d[a] ^ d[b];
		
		//printf("%d %d %d\n",a,b,w);
		
		insert(w);
	}
	
	cout << gausscek(d[n]) << endl;
    
    return 0;
}