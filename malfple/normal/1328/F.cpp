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

int n,k;
map<int,int>cnt;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n>>k;
    ll sumless = 0, summore = 0;
    int cntless = 0, cntmore = 0;
    REP(i,1,n){
        int x;
        cin>>x;
        cnt[x]++;
        summore += x;
        cntmore++;
    }
    // printf("ok\n");

    ll ans = INF;
    for(auto x : cnt){
        summore -= (ll)x.F * x.S;
        cntmore -= x.S;

        if(x.S >= k){
            ans = 0;
        }else{
            int need = k - x.S;
            ll tless = (ll)cntless * x.F - sumless;
            ll tmore = summore - (ll)cntmore * x.F;

            // printf("test %d\n",x.F);

            // less only
            if(cntless >= need){
                int over = cntless - need;
                ans = min(ans, tless - over);
                // printf("less only %lld\n",tless - over);
            }

            // more only
            if(cntmore >= need){
                int over = cntmore - need;
                ans = min(ans, tmore - over);
                // printf("more only %lld\n",tmore - over);
            }

            // both
            int over = cntless + cntmore - need;
            ans = min(ans, tless + tmore - over);
            // printf("both %lld\n",tless + tmore - over);
        }

        sumless += (ll)x.F * x.S;
        cntless += x.S;
    }

    cout << ans << endl;

    return 0;
}