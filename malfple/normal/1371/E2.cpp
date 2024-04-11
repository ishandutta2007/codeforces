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

int n,p;

int a[N];
int pa, cnt;

multiset<int>st;
queue<int>q;
int offset = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n>>p;
    REP(i,1,n){
        cin>>a[i];
    }

    sort(a+1, a+n+1);
    pa = 1; cnt = 0;

    int lo = max(0, a[n] - n + 1), hi = a[n];

    // gen st for x = lo
    REP(i,1,n){
        while(pa <= n && a[pa] <= lo+i-1){
            cnt++;
            pa++;
        }

        st.insert(cnt - i + 1);
        q.push(cnt - i + 1);
    }

    vi ans;
    REP(i,lo,hi){
        auto it = st.begin();
        int mn = (*it) + offset;
        it = st.end(); it--;
        int mx = (*it) + offset;

        if(mn <= 0){
            // not possible
        }else if(mx >= p){
            // then p will exist
        }else{
            ans.pb(i);
        }

        // advance
        st.erase(st.find(q.front()));
        q.pop();

        offset++;

        // next number must be 1
        st.insert(1 - offset);
        q.push(1 - offset);
    }

    cout << ans.size() << endl;
    for(auto x : ans){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}