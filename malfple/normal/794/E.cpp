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

const int N = 3e5 + 5;

int n;
int arr[N];

int mxs[2];
int parr[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n;
    REP(i,1,n)cin>>arr[i];
    REP(i,1,n-1)parr[i] = min(arr[i], arr[i+1]);

    if(n&1){
        mxs[0] = arr[n/2+1];
    }else{
        mxs[1] = parr[n/2];
    }

    REV(i,n,2){
        int g = i&1;
        if(g){
            int l = (i-1)/2;
            int r = n - (i-1)/2;
            mxs[1] = max(mxs[1], parr[l]);
            mxs[1] = max(mxs[1], parr[r]);
            cout << mxs[1] << " ";
        }else{
            int l = i/2;
            int r = n - i/2 + 1;
            mxs[0] = max(mxs[0], arr[l]);
            mxs[0] = max(mxs[0], arr[r]);
            cout << mxs[0] << " ";
        }
    }

    int ans1 = 0;
    REP(i,1,n){
        ans1 = max(ans1, arr[i]);
    }
    cout << ans1 << endl;

    return 0;
}