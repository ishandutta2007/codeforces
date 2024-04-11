    
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

#define right laksjdf

const int N = 5e5 + 5;

int n,m,q;
int cnt[N];
vii vec;
vector<ll> pf;

ll k[N];
vector<pair<ll,int> >sorter;
int ans[N];

ll get_used(ll lim){
    if(lim > 2e18 / m){
        return 2e18;
    }
    ll ret = lim * m;
    int lo = 0, hi = m-1, ans = m;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(vec[mid].F > lim){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    
    if(ans < m){
        ret += pf[ans] - (lim * (m - ans));
    }
    return ret;
}

ll binser_cycle(ll k){
    ll lo = 1, hi = 2e18, ret = 0;
    while(lo <= hi){
        ll mid = (lo+hi)/2;
        ll v = get_used(mid);
        if(v < k){
            ret = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    return ret;
}

int bitt[N];
void update(int x, int v){
    REPP(i,x,N-5,i&-i){
        bitt[i] += v;
    }
}
int query(int x){
    int ret = 0;
    REVV(i,x,1,i&-i){
        ret += bitt[i];
    }
    return ret;
}
int getkth(ll kth){
    assert(kth > 0 && kth <= m);
    int lo = 1, hi = m, ret = m+1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        int tmp = mid - query(mid);
        if(tmp >= kth){
            ret = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    assert(ret <= m);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    
    cin>>n>>m>>q;
    REP(i,1,n){
        int x;
        cin>>x;
        cnt[x]++;
    }
    REP(i,1,m){
        vec.pb(mp(cnt[i], i));
    }
    sort(vec.begin(), vec.end());
    
    pf.resize(vec.size(), 0);
    FORD(i, pf.size()){
        pf[i] = vec[i].F;
        if(i+1 < pf.size())pf[i] += pf[i+1];
    }
    
    REP(i,1,q){
        cin>>k[i];
        sorter.pb(mp(k[i], i));
    }
    sort(sorter.begin(), sorter.end());
    
    REP(i,1,m)update(i, 1); // setup bitt
    
    int stallp = 0;
    FOR(i,sorter.size()){
        int id = sorter[i].S;
        ll cycles = binser_cycle(k[id]);
        
//        printf("query %d %lld -> cycles: %lld\n",id,k[id],cycles);
        
        while(stallp < vec.size() && vec[stallp].F <= cycles){
            update(vec[stallp].S, -1);
            stallp++;
        }
        
        ll left = k[id] - get_used(cycles);
//        printf("kth: %lld\n",left);
        
        ans[id] = getkth(left);
        
//        printf("ans: %lld\n",ans[id]);
    }
    
    REP(i,1,q){
        cout << ans[i] << endl;
    }
    
    return 0;
}