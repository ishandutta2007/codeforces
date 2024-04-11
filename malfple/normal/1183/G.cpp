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

//end of macro

const int N = 2e5 + 5;

int t;
int n;
int cnt[N], fcnt[N];
priority_queue<pii>init;
priority_queue<int>stall;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    
    cin>>t;
    while(t--){
        cin>>n;
        REP(i,1,n){
            int x,y;
            cin>>x>>y;
            cnt[x]++;
            if(y == 1)fcnt[x]++;
        }
        while(!init.empty())init.pop();
        while(!stall.empty())stall.pop();
        REP(i,1,n){
            if(cnt[i] > 0)init.push(mp(cnt[i], fcnt[i]));
            cnt[i] = fcnt[i] = 0;
        }
        int prev = OO;
        int ans = 0, fff = 0;
        while(prev > 0){
            if(stall.empty()){
                if(init.empty())break;
                prev = min(prev, init.top().F);
            }
            while(!init.empty() && init.top().F >= prev){
                stall.push(init.top().S);
                init.pop();
            }
            ans += prev;
            fff += min(prev, stall.top());
            stall.pop();
            prev--;
        }
        cout << ans << " " << fff << endl;
    }
    
    return 0;
}