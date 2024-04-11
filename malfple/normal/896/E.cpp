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
const int BLOCK = 200;
const int NB = N/BLOCK+1;

int n,m;
int arr[N];

int p[NB][N];
int cnt[NB][N];
int offset[NB], maxval[NB];

int cek(int b, int x){
    if(p[b][p[b][x]] != p[b][x])p[b][x] = cek(b, p[b][x]);
    return p[b][x];
}

void build(int b){
    int s = b*BLOCK;
    maxval[b] = 0;
    offset[b] = 0;
    REP(i,s,min(s+BLOCK-1, n-1)){
        maxval[b] = max(maxval[b], arr[i]);
    }

    REP(i,1,maxval[b]){
        cnt[b][i] = 0;
        p[b][i] = i;
    }

    REP(i,s,min(s+BLOCK-1, n-1)){
        cnt[b][arr[i]]++;
    }
}

void update(int b, int x){
    // printf("update %d\n",b);
    if(offset[b] + x >= maxval[b])return;

    if(x < maxval[b]-offset[b]-x){ // merge bot to top
        REP(i, offset[b] + 1, offset[b] + x){
            p[b][i] = i+x;
            cnt[b][i+x] += cnt[b][i];
        }
        offset[b] += x;
    }else{ // top to bot
        REP(i, offset[b] + x + 1, maxval[b]){
            p[b][i] = i-x;
            cnt[b][i-x] += cnt[b][i];
        }
        maxval[b] = offset[b] + x;
    }
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
    FOR(i,n)cin>>arr[i];

    // build segment array
    FOR(i,n){
        if(i % BLOCK == 0){
            build(i / BLOCK);
        }
    }

    while(m--){
        int op, l, r, x;
        cin>>op>>l>>r>>x;
        l--; r--;
        if(op == 1){
            // update >x ? -x : -0

            REP(i,l,r){
                if(i % BLOCK == 0 && i+BLOCK-1 <= r){
                    update(i / BLOCK, x);
                    i = i+BLOCK-1;
                }else{
                    arr[i] = cek(i/BLOCK, arr[i]);
                    assert(arr[i] > offset[i/BLOCK] && arr[i] <= maxval[i/BLOCK]);

                    if(arr[i] > offset[i/BLOCK] + x){
                        cnt[i/BLOCK][arr[i]]--;
                        arr[i] -= x;
                        cnt[i/BLOCK][arr[i]]++;
                    }
                }
            }
        }else{
            // query cnt(x)

            int ans = 0;
            REP(i,l,r){
                if(i % BLOCK == 0 && i+BLOCK-1 <= r){
                    if(offset[i/BLOCK] + x <= maxval[i/BLOCK]){
                        ans += cnt[i/BLOCK][offset[i/BLOCK] + x];
                    }
                    i = i+BLOCK-1;
                }else{
                    arr[i] = cek(i/BLOCK, arr[i]);
                    assert(arr[i] > offset[i/BLOCK] && arr[i] <= maxval[i/BLOCK]);

                    if(arr[i] == offset[i/BLOCK] + x){
                        ans++;
                    }
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}