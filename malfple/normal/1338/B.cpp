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

const int N = 1e5 + 5;

int n;
vi lst[N];

int col[N];
void bicolor(int now, int par){
    FOR(i,lst[now].size()){
        int to = lst[now][i];
        if(to == par)continue;

        col[to] = col[now]^1;
        bicolor(to, now);
    }
}

set<int>st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n;
    REP(i,2,n){
        int a,b;
        cin>>a>>b;
        lst[a].pb(b);
        lst[b].pb(a);
    }

    col[1] = 0;
    bicolor(1, -1);

    int ans_min = 1;
    int bicolorc = -1;
    REP(i,1,n){
        if(lst[i].size() == 1){
            if(bicolorc == -1)bicolorc = col[i];
            else if(bicolorc != col[i]){
                ans_min = 3;
                break;
            }
        }
    }

    int ans_max = n-1;
    REP(i,1,n){
        if(lst[i].size() == 1){
            if(st.count(lst[i][0])){
                ans_max--;
            }
            st.insert(lst[i][0]);
        }
    }

    cout << ans_min << " " << ans_max << endl;

    return 0;
}