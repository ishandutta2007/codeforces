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

int t;
int n;
int p[N];
int c[N];

bool used[N];
vector<int>vec;

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
        REP(i,1,n)cin>>p[i];
        REP(i,1,n)cin>>c[i];

        REP(i,1,n){
            used[i] = false;
        }

        int ans = OO;
        REP(i,1,n){
            if(used[i])continue;

            vec.clear();
            int now = i;
            while(!used[now]){
                vec.pb(c[now]);
                used[now] = true;
                now = p[now];
            }

            int m = vec.size();
            // printf("vec at %d\n",i);
            // FOR(x,vec.size())printf("%d ",vec[x]); printf("\n");
            ans = min(ans, m);
            REP(f,1,m){
                if(m % f != 0)continue;
                if(f >= ans)continue;
                REP(k,0,f-1){
                    bool can = true;
                    int col = -1;
                    REPP(j,k,m-1,f){
                        if(col == -1)col = vec[j];
                        else if(col != vec[j]){
                            can = false;
                            break;
                        }
                    }
                    if(can){
                        // printf("can %d\n",f);
                        ans = min(ans, f);
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}