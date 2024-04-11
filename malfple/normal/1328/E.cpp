//pragma
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

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

#define pb push_back
#define F first
#define S second

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

const int N = 2e5 + 5;
const int B = 18;

int n,m;
vi lst[N];

int depth[N];
int sparset[N][B+1];
void idfs(int now, int par){
	sparset[now][0] = par;
	FOR(i,lst[now].size()){
		int to = lst[now][i];
		if(to == par)continue;
		depth[to] = depth[now]+1;
		idfs(to, now);
	}
}

vector<int>qq;
bool cmp(int a, int b){
	return depth[a] > depth[b];
}

int lift(int now, int h){ // lift to height h
	REV(i,B,0){
		if(sparset[now][i] == -1 || depth[sparset[now][i]] < h)continue;
		now = sparset[now][i];
	}
	return now;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n>>m;
    REP(i,2,n){
    	int a,b;
    	cin>>a>>b;
    	lst[a].pb(b);
    	lst[b].pb(a);
    }

    depth[1] = 0;
    idfs(1, -1);

    REP(i,0,B-1){
    	REP(j,1,n){
    		if(sparset[j][i] == -1)sparset[j][i+1] = -1;
    		else sparset[j][i+1] = sparset[sparset[j][i]][i];
    	}
    }

    while(m--){
    	qq.clear();
    	int k;
    	cin>>k;
    	REP(i,1,k){
    		int x;
    		cin>>x;
    		if(x == 1)continue;
    		if(sparset[x][0] == 1)continue;
    		qq.pb(sparset[x][0]);
    	}

    	if(qq.size() == 0){
    		cout << "YES" << endl;
    	}else{
    		sort(qq.begin(), qq.end(), cmp);
    		bool ok = true;
    		for(int i=1; i<qq.size(); i++){
    			int a = qq[i-1];
    			int b = qq[i];

    			a = lift(a, depth[b]);
    			if(a != b)ok = false;
    		}
    		if(ok)cout << "YES" << endl;
    		else cout << "NO" << endl;
    	}
    }

    return 0;
}