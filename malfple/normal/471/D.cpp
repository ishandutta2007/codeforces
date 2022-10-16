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

const int N = 2e5 + 5;

int n,w;
int a[N], b[N];
int sa[N], sb[N];

//str -> searched string
//pat -> search pattern
int kmp[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n>>w;
    FOR(i,n)cin>>a[i];
    FOR(i,w)cin>>b[i];

    n--;
    w--;
    REP(i,0,n-1){
        sa[i] = a[i+1] - a[i];
    }
    REP(i,0,w-1){
        sb[i] = b[i+1] - b[i];
    }

    kmp[0] = -1;
    for(int i=0, j=-1; i < w; i++, j++){
        while ((j >= 0) && (sb[i] != sb[j])) j = kmp[j];
        kmp[i+1] = j+1;
    }

    int found = 0;
    for(int i=0, j=0; i < n; i++, j++){
        while ((j >= 0) && (sa[i] != sb[j])) j = kmp[j];
        if (j+1 == w){
            found++;
            j = kmp[j];
        }
    }
    if(w == 0)found++;
    cout << found << endl;

    return 0;
}