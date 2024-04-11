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

const int N = 1005;

int n;
ll ax[N], ay[N], bx[N], by[N];
set<pll>st[N];
set<pll>st2;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    
    cin>>n;
    REP(i,1,n){
    	cin>>ax[i]>>ay[i]>>bx[i]>>by[i];
    	
    	REP(j,1,i-1){
    		ll d = (ax[i]-bx[i]) * (ay[j]-by[j]) - (ay[i]-by[i]) * (ax[j]-bx[j]);
    		
    		//printf("%d and %d, d = %lld\n",i,j,d);
    		
    		if(d != 0){
    			ll x = (ax[i]*by[i] - ay[i]*bx[i]) * (ax[j]-bx[j]) - (ax[i]-bx[i]) * (ax[j]*by[j] - ay[j]*bx[j]);
    			ll y = (ax[i]*by[i] - ay[i]*bx[i]) * (ay[j]-by[j]) - (ay[i]-by[i]) * (ax[j]*by[j] - ay[j]*bx[j]);
    			
    			//printf("%lld %lld\n",x,y);
    			
    			if(x%d == 0 && y%d == 0){ // integer coordinate
    				x /= d;
    				y /= d;
    				//printf("i-co %lld %lld\n",x,y);
    				
    				if(x >= min(ax[i], bx[i]) && x <= max(ax[i], bx[i]) && y >= min(ay[i], by[i]) && y <= max(ay[i], by[i])){
    					st[i].insert(mp(x,y));
					}
					if(x >= min(ax[j], bx[j]) && x <= max(ax[j], bx[j]) && y >= min(ay[j], by[j]) && y <= max(ay[j], by[j])){
    					st[j].insert(mp(x,y));
					}
				}
			}
		}
	}
	
	ll ans = 0;
	REP(i,1,n){
		int spx = max(ax[i], bx[i]) - min(ax[i],bx[i]);
		int spy = max(ay[i], by[i]) - min(ay[i],by[i]);
		ans += __gcd(spx, spy) + 1 - st[i].size();
		//printf("%d: %d\n",i,st[i].size());
		for(set<pll>::iterator it = st[i].begin(); it != st[i].end(); it++)st2.insert(*it);
	}
	cout << ans + st2.size() << endl;

    return 0;
}