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

const int N = 1e6 + 5;

int n,m;
priority_queue<pii>pq;
int v[N];
vi atk[N];

bool cek(int x, int turns){
    priority_queue<pii>tpq = pq;
    
    while(!pq.empty()){
        pii t = pq.top();
        pq.pop();
        turns -= t.F / x;
        if(turns <= 0)break;
    }
    
    pq = tpq;
    return turns <= 0;
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
    int sum = 0;
    REP(i,1,m){
        int x;
        cin>>x;
        pq.push(mp(x, i));
        sum += x;
    }
    int turns = sum / n;
    if(sum % n)turns++;
    
//    printf("turn %d\n",turns);
    
    if(n <= m){
        REP(i,1,m){
            if(i > n){
                atk[i].resize(turns, 1);
                continue;
            }
            v[i] = 1;
            REP(j,1,turns){
                if(pq.empty())atk[i].pb(1);
                else{
                    pii t = pq.top();
                    pq.pop();
                    atk[i].pb(t.S);
                    t.F--;
                    pq.push(t);
                }
            }
        }
    }else{
        REP(i,1,m){
//            printf("at %d\n",i);
            if(i == m){
                v[i] = n;
                n = 0;
                REP(j,1,turns){
                    if(pq.empty())atk[i].pb(1);
                    else{
                        pii t = pq.top(); pq.pop();
                        atk[i].pb(t.S);
                        t.F -= v[i];
                        if(t.F > 0)pq.push(t);
                    }
                }
            }else if(turns > pq.size()){
                int lo = 1, hi = OO, ans = 0;
                while(lo <= hi){
                    int mid = (lo+hi)/2;
                    if(cek(mid, turns)){
                        ans = mid;
                        lo = mid+1;
                    }else{
                        hi = mid-1;
                    }
                }
                
                if(ans == 0){
                    v[i] = n;
                    n = 0;
                }else{
                    v[i] = ans;
                    n -= ans;
                }
                REP(j,1,turns){
                    if(pq.empty())atk[i].pb(1);
                    else{
                        pii t = pq.top(); pq.pop();
                        atk[i].pb(t.S);
                        t.F -= v[i];
                        if(t.F > 0)pq.push(t);
                    }
                }
            }else{
                vii vec;
                int mn = OO;
                REP(j,1,turns){
                    vec.pb(pq.top());
                    mn = min(mn, pq.top().F);
                    pq.pop();
                }
                assert(mn <= n);
                n -= mn;
                v[i] = mn;
                FOR(j,vec.size()){
                    atk[i].pb(vec[j].S);
                    vec[j].F -= mn;
                    if(vec[j].F > 0){
                        pq.push(vec[j]);
                    }
                }
            }
        }
    }
    
    REP(i,1,m){
        while(atk[i].size() < turns)atk[i].pb(1);
    }
    
    cout << turns << endl;
    REP(i,1,m)cout << v[i] << " ";
    cout << endl;
    FOR(i,turns){
        REP(j,1,m)cout << atk[j][i] << " ";
        cout << endl;
    }
    
    return 0;
}