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

const int N = 1e3 + 5;

int n,a,b;
bool flip = false;
bool arr[N][N];

inline void connect(int a, int b){
    arr[a][b] = arr[b][a] = true;
}

inline void printGrid(){
    if(flip){
        REP(i,1,n){
            REP(j,1,n){
                if(i == j)continue;
                arr[i][j] ^= 1;
            }
        }
    }
    REP(i,1,n){
        REP(j,1,n){
            cout << arr[i][j];
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>a>>b;
    if(a < b){
        swap(a,b);
        flip = true;
    }

    if(n == 1){
        cout << "YES" << endl;
        cout << '0' << endl;
        return 0;
    }
    if(n <= 3 && a == 1){
        cout << "NO" << endl;
        return 0;
    }

    if(b == 1){
        cout << "YES" << endl;
        REP(i,1,n-a){
            connect(i, i+1);
        }
        printGrid();
    }else cout << "NO" << endl;

    return 0;
}