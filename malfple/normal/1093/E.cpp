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

const int BLOCK = 1700;
const int N = 2e5 + 5;

int n,m;
int pa[N];
int arr[N];

int op[N],a[N],b[N],c[N],d[N];

vii vq;
int ans[N];
int bitt[N];
void update(int x, int v){
    //printf("update at %d\n",x);
    REPP(i,x,N-5,i&-i)bitt[i] += v;
}
int query(int x){
    int ret = 0;
    REVV(i,x,1,i&-i)ret += bitt[i];
    return ret;
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
    REP(i,1,n){
        int x;
        cin>>x;
        pa[x] = i;
    }
    REP(i,1,n){
        cin>>arr[i];
        arr[i] = pa[arr[i]];
    }
    //printf("arr\n");
    //REP(i,1,n)printf("%d ",arr[i]);printf("\n");
    
    REP(i,1,m){
        cin>>op[i]>>a[i]>>b[i];
        if(op[i] == 1){
            cin>>c[i]>>d[i];
        }
    }
    
    REP(i,1,m){
        if(i % BLOCK == 1){
            FOR(j,vq.size()){
                swap(arr[vq[j].F], arr[vq[j].S]);
            }
            REP(j,1,n)pa[arr[j]] = j;
            vq.clear();
            REP(j,i,min(m, i+BLOCK-1)){
                if(op[j] == 1){
                    vq.pb(mp(b[j], j));
                    vq.pb(mp(a[j]-1, -j));
                }
            }
            sort(vq.begin(), vq.end());
            memset(bitt, 0, sizeof bitt);
            int curr = 1;
            FOR(j,vq.size()){
                int sign = 1;
                if(vq[j].S < 0){
                    vq[j].S = -vq[j].S;
                    sign = -1;
                }
                while(vq[j].F >= curr){
                    update(pa[curr], 1);
                    curr++;
                }
                int cnt = query(d[vq[j].S]) - query(c[vq[j].S]-1);
                ans[vq[j].S] += sign * cnt;
                //printf("fill query %d -> %d\n",vq[j].S,vq[j].F);
            }
            vq.clear();
        }

        if(op[i] == 1){
            FOR(j,vq.size()){
                if(vq[j].F >= c[i] && vq[j].F <= d[i] && arr[vq[j].F] >= a[i] && arr[vq[j].F] <= b[i])ans[i]--;
                if(vq[j].S >= c[i] && vq[j].S <= d[i] && arr[vq[j].S] >= a[i] && arr[vq[j].S] <= b[i])ans[i]--;
                swap(arr[vq[j].F], arr[vq[j].S]);
                if(vq[j].F >= c[i] && vq[j].F <= d[i] && arr[vq[j].F] >= a[i] && arr[vq[j].F] <= b[i])ans[i]++;
                if(vq[j].S >= c[i] && vq[j].S <= d[i] && arr[vq[j].S] >= a[i] && arr[vq[j].S] <= b[i])ans[i]++;
            }
            FORD(j,vq.size()){
                swap(arr[vq[j].F], arr[vq[j].S]);
            }
            cout << ans[i] << endl;
        }else{
            if(a[i] > b[i])swap(a[i], b[i]);
            vq.pb(mp(a[i],b[i]));
        }
    }

    return 0;
}