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
const int BLOCK = sqrt(N);

vi divi[N];

int n;
int arr[N];
vii queries;
int ans[N];

bool cmp(pii a, pii b){
	if(a.F/BLOCK == b.F/BLOCK){
		return a.S < b.S;
	}return a.F/BLOCK < b.F/BLOCK;
}

int cl=0,cr=-1;
int cnt[N];
void modify(int x, int f){ // f=1 add, f=-1 remove
	FOR(i,divi[x].size()){
		cnt[divi[x][i]] += f;
	}
}
void move(int l, int r){
	while(cl > l){
		modify(arr[--cl], 1);
	}
	while(cr < r){
		modify(arr[++cr], 1);
	}
	while(cl < l){
		modify(arr[cl++], -1);
	}
	while(cr > r){
		modify(arr[cr--], -1);
	}
}

#define debugd

int main(){
	#ifndef debug
    OPTIMIZE();
    #endif
    
	int id = 0;
	REP(i,1,N-5){
		REPP(j,i,N-5,i){
			divi[j].pb(i);
		}
	}
	
	cin>>n;
	REP(i,1,n){
		int x;
		cin>>arr[i]>>x;
		queries.pb(mp(i-x,i));
	}
	sort(queries.begin(), queries.end(), cmp);
	FOR(i,queries.size()){
		int now = queries[i].S;
		move(queries[i].F, now-1);
		//printf("at %d, q range %d %d\n",now,queries[i].F, now-1);
		//REP(i,1,N-5)if(cnt[i])printf("%d\n",i);
		
		int d = arr[now];
		FOR(j,divi[d].size()){
			if(!cnt[divi[d][j]])ans[now]++;
		}
	}
	
	REP(i,1,n){
		cout << ans[i] << endl;
	}
	
	#ifdef debug
	system("pause");
	#endif
    return 0;
}