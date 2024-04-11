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

const int N = 605;

int n;
int a[N], b[N];

short memo[N][N];
int ch[N][N];
short dp(int l, int r){
    if(l > r)return 1;
    short& ret = memo[l][r];
    if(ret != -1)return ret;

    ret = 0;
    REPP(i,1,b[l], 2){
        if(i < a[l])continue;
        int s = i-1;
        if(l + s/2 > r)break;

        if(dp(l+1, l+s/2) == 1 && dp(l+s/2+1, r) == 1){
            ret = 1;
            ch[l][r] = i;
            break;
        }
    }

    return ret;
}

void bt(int l, int r){
    if(l > r)return;

    int i = ch[l][r];
    int s = i-1;
    cout << "(";
    bt(l+1, l+s/2);
    cout << ")";
    bt(l+s/2+1, r);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n;
    REP(i,1,n)cin>>a[i]>>b[i];

    memset(memo, -1, sizeof memo);
    if(dp(1, n) == 1){
        bt(1, n);
        cout << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}