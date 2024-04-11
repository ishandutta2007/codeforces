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

const int N = 1e5 + 5;

int n,m;
int cnt[1<<9];
int p[N];
int pizza[1<<9], pizza2[1<<9];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n>>m;
    REP(i,1,n){
        int k;
        cin>>k;
        int mask = 0;
        REP(j,1,k){
            int x;
            cin>>x;
            mask |= 1<<(x-1);
        }
        cnt[mask]++;
    }

    for(int i = 0;i < 9; ++i){
        for(int mask = 0; mask < (1<<9); ++mask){
            if(mask & (1<<i))
                cnt[mask] += cnt[mask^(1<<i)];
        }
    }

    FOR(i,(1<<9)){
        pizza[i] = N-1;
        pizza2[i] = N-1;
    }
    p[N-1] = OO+5;
    REP(i,1,m){
        cin>>p[i];
        int k;
        cin>>k;
        int mask = 0;
        REP(j,1,k){
            int x;
            cin>>x;
            mask |= 1<<(x-1);
        }
        if(p[pizza2[mask]] > p[i])
            pizza2[mask] = i;
        if(p[pizza2[mask]] < p[pizza[mask]])
            swap(pizza[mask], pizza2[mask]);
    }

    int ans = -1;
    int price;
    int a,b;
    FOR(i,(1<<9)){
        if(pizza[i] == N-1)continue;
        FOR(j,(1<<9)){
            if(pizza[j] == N-1)continue;
            if(i == j && pizza2[j] == N-1)continue;

            int ta = pizza[i];
            int tb = pizza[j];
            if(i == j)tb = pizza2[j];

            // printf("match pizza %d %d\n",ta,tb);

            int curr = cnt[i | j];
            int tp = p[ta] + p[tb];
            if(curr > ans){
                ans = curr;
                price = tp;
                a = ta;
                b = tb;
            }else if(curr == ans && price > tp){
                price = tp;
                a = ta;
                b = tb;
            }
        }
    }

    cout << a << " " << b << endl;

    return 0;
}