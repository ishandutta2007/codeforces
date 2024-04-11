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

const int N = 45;

int n;
int x[N], y[N];

bool cek(int i){
    int x1 = OO, y1 = OO, x2 = -OO, y2 = -OO;
    REP(j,1,n){
        if(i == j)continue;
        x1 = min(x1, x[j]);
        y1 = min(y1, y[j]);
        x2 = max(x2, x[j]);
        y2 = max(y2, y[j]);
    }
    bool fail = false;
    REP(j,1,n){
        if(i == j)continue;
        if(x[j] != x1 && x[j] != x2 && y[j] != y1 && y[j] != y2){
            fail = true;
        }
    }
    return !fail;
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
    n = 4*n+1;
    REP(i,1,n){
        cin>>x[i]>>y[i];
    }
    int x1 = OO, y1 = OO, x2 = -OO, y2 = -OO;
    REP(j,1,n){
        x1 = min(x1, x[j]);
        y1 = min(y1, y[j]);
        x2 = max(x2, x[j]);
        y2 = max(y2, y[j]);
    }
    int cx1 = 0, cx2 = 0, cy1 = 0, cy2 = 0;
    REP(i,1,n){
        if(x[i] == x1)cx1++;
        if(x[i] == x2)cx2++;
        if(y[i] == y1)cy1++;
        if(y[i] == y2)cy2++;
    }
    if(cx1 == 1){
        REP(i,1,n){
            if(x[i] == x1){
                cout << x[i] << " " << y[i] << endl;
                return 0;
            }
        }
    }else if(cx2 == 1){
        REP(i,1,n){
            if(x[i] == x2){
                cout << x[i] << " " << y[i] << endl;
                return 0;
            }
        }
    }else if(cy1 == 1){
        REP(i,1,n){
            if(y[i] == y1){
                cout << x[i] << " " << y[i] << endl;
                return 0;
            }
        }
    }else if(cy2 == 1){
        REP(i,1,n){
            if(y[i] == y2){
                cout << x[i] << " " << y[i] << endl;
                return 0;
            }
        }
    }else{
        REP(i,1,n){
            if(cek(i)){
                cout << x[i] << " " << y[i] << endl;
                return 0;
            }
        }
    }
    
    return 0;
}