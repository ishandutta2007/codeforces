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

#define ALL(v) v.begin(), v.end()

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

const int N = 1e3 + 5;

int n;
int arr[N];

int ask(int l, int r){
    cout << "? " << l << " " << r << endl;
    int res;
    cin>>res;
    return res;
}

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    // #define endl '\n'
    // cout.setf(ios::fixed);
    // cout.setf(ios::showpoint);
    // cout.precision(10);

    cin>>n;
    int a = ask(1, 2);
    int b = ask(2, 3);
    int c = ask(1, 3);

    arr[2] = a + b - c;
    arr[1] = a - arr[2];
    arr[3] = b - arr[2];

    REP(i,4,n){
        int x = ask(i-1, i);
        arr[i] = x - arr[i-1];
    }

    cout << "! ";
    REP(i,1,n){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}