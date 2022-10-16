    
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

#define right laksjdf

const int N = 1005;

int n,m;
char arr[N][N];
int right[N][N];
int down[N][N];

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
        REP(j,1,m){
            cin>>arr[i][j];
        }
    }
    
    // right
    REP(i,1,n){
        right[i][m] = m;
        REV(j,m-1,1){
            if(arr[i][j] == arr[i][j+1]){
                right[i][j] = right[i][j+1];
            }else{
                right[i][j] = j;
            }
        }
    }
    
    // down
    REP(j,1,m){
        down[n][j] = n;
        REV(i,n-1,1){
            if(arr[i][j] == arr[i+1][j]){
                down[i][j] = down[i+1][j];
            }else{
                down[i][j] = i;
            }
        }
    }
    
    ll ans = 0;
    REP(j,1,m){
//        printf("column %d\n",j);
        for(int i=1; i<=n; i=down[i][j]+1){
            int i2 = down[i][j]+1;
            if(i2 > n)break;
            int i3 = down[i2][j]+1;
            if(i3 > n)break ;
            int ie = down[i3][j]+1;
            
            int w = i3-i2;
            if(i2-i < w)continue;
            if(ie-i3 < w)continue;
            
            int l = OO;
            REP(k,i2,i3-1)l = min(l, right[k][j]);
            REP(k,i2-w,i2-1)l = min(l, right[k][j]);
            REP(k,i3,i3+w-1)l = min(l, right[k][j]);
            
//            printf("%d-%d-%d-%d = %d\n",i,i2,i3,ie,l-j+1);
            
            ans += l-j+1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}