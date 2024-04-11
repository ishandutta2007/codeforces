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

const int N = 1005;

int t;
int n;

int arr[N];
multiset<int>st;

int mex(){
	int ret = -1;
	for(auto x : st){
		if(x == ret)continue;
		if(x == ret+1){
			ret++;
			continue;
		}
		break;
	}
	return ret+1;
}

vi ans;

void sett(int now, int v){
	// printf("set %d -> %d\n",now,v);
	st.erase(st.find(arr[now]));
	ans.pb(now);
	arr[now] = v;
	st.insert(v);
}

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
    	st.clear();
    	ans.clear();

    	REP(i,1,n){
    		cin>>arr[i];
    		st.insert(arr[i]);
    	}

    	int now = 1;
    	while(now <= n){
    		// printf("%d now %d\n",n,now);
    		if(arr[now] == now-1){
    			now++;
    		}else{
    			int m = mex();
    			// printf("mex %d\n",m);
    			if(m == now-1){
    				sett(now, m);
    				now++;
    			}else{
    				if(m < n && arr[m+1] != m){
    					sett(m+1, m);
    				}else{
    					int rem = now+1;
    					while(arr[rem] != now-1)rem++;
    					// printf("rem %d\n",rem);
    					sett(rem, m);
    				}
    			}
    		}
    	}

    	cout << ans.size() << endl;
    	for(auto x : ans){
    		cout << x << " ";
    	}
    	cout << endl;
    }

    return 0;
}