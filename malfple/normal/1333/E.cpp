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

const int N = 505;

const int rx[] = {0,1,0,-1};
const int ry[] = {1,0,-1,0};
const int qx[] = {0,1,0,-1,1,1,-1,-1};
const int qy[] = {1,0,-1,0,1,-1,1,-1};

int n;
int arr[N][N];

bool vis[N][N];
void findleast(int& x, int& y){
    int mn = OO;
    REP(i,1,n){
        REP(j,1,n){
            if(vis[i][j])continue;
            if(arr[i][j] < mn){
                x = i;
                y = j;
                mn = arr[i][j];
            }
        }
    }
    if(mn == OO)x = -1, y = -1;
}
int move(const int cx[], const int cy[], int s){
    memset(vis, 0, sizeof vis);
    int x, y;
    findleast(x, y);
    int ret = 0;

    while(1){
        int nx = -1, ny;
        int mn = OO;

        FOR(k,s){
            for(int d = 1; ; d++){
                int tx = x + cx[k] * d;
                int ty = y + cy[k] * d;
                if(tx < 1 || tx > n || ty < 1 || ty > n)break;
                if(vis[tx][ty])continue;
                if(arr[tx][ty] < mn){
                    mn = arr[tx][ty];
                    nx = tx;
                    ny = ty;
                }
            }
        }

        if(nx == -1){
            ret++;
            findleast(nx, ny);
        }

        if(nx == -1)break;
        x = nx;
        y = ny;
        vis[x][y] = 1;
    }
    return ret;
}
int queen(){
    return move(qx, qy, 8);
}
int rook(){
    return move(rx, ry, 4);
}

vi vec;
void bf(){
    vec.clear();
    REP(i,1,n*n)vec.pb(i);
    do{
        int k = 0;
        REP(i,1,n){
            REP(j,1,n){
                arr[i][j] = vec[k++];
            }
        }

        // printf("%d - %d\n",rook(),queen());
        if(rook() < queen()){
            // printf("found\n");
            break;
        }
    }while(next_permutation(vec.begin(), vec.end()));
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
    if(n <= 2){
        cout << -1 << endl;
    }else if(n == 3){
        bf();
        REP(i,1,n){
            REP(j,1,n){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }else{
        int k = n*n;
        arr[n][n-1] = k--;
        arr[n-2][n] = k--;
        arr[n-1][n] = k--;
        arr[n-1][n-1] = k--;
        arr[n][n-2] = k--;
        arr[n][n] = k--;
        arr[n][n-3] = k--;

        int last  = n-3;
        REV(i,n,1){
            REP(j,1,n){
                if(arr[i][j] == 0){
                    arr[i][j] = k--;
                    last = j;
                }
            }
            if(i > 1){
                arr[i-1][last] = k--;
            }
        }

        REP(i,1,n){
            REP(j,1,n){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}