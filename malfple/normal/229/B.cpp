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

#define mp make_pair

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

inline void OPTIMIZE(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
}

//end of macro

const int N = 1e5 + 5;

int n,m;
vii lst[N];
set<int>kek[N];

priority_queue<pii>pq;
bool vis[N];

int main(){
    OPTIMIZE();
	
	cin>>n>>m;
	REP(i,1,m){
		int a,b,c;
		cin>>a>>b>>c;
		lst[a].pb(mp(b,c));
		lst[b].pb(mp(a,c));
	}
	REP(i,1,n){
		int x;
		cin>>x;
		REP(j,1,x){
			int y;
			cin>>y;
			kek[i].insert(y);
		}
	}
	
	pq.push(mp(0,1));
	
	int ans = -1;
	while(!pq.empty()){
		int t = -pq.top().F;
		int now = pq.top().S;
		pq.pop();
		
		if(now == n){
			ans = t;
			break;
		}
		if(vis[now])continue;
		vis[now] = true;
		
		while(kek[now].find(t) != kek[now].end())t++;
		FOR(i,lst[now].size()){
			pq.push(mp(-t-lst[now][i].S, lst[now][i].F));
		}
	}
	
	cout << ans << endl;
	
	//system("pause");
    return 0;
}