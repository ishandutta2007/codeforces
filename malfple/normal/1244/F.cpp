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

int n,k;

string str;
bool single[N];

int dist[N];
char col[N];

void reflex(){
    REP(i,1,n-1){
        if(dist[i] > dist[i-1]+1){
            dist[i] = dist[i-1]+1;
            col[i] = col[i-1];
        }
    }
    if(dist[0] > dist[n-1]+1){
        dist[0] = dist[n-1]+1;
        col[0] = col[n-1];
    }
    REP(i,1,n-1){
        if(dist[i] > dist[i-1]+1){
            dist[i] = dist[i-1]+1;
            col[i] = col[i-1];
        }
    }
    
    REV(i,n-2,0){
        if(dist[i] > dist[i+1]+1){
            dist[i] = dist[i+1]+1;
            col[i] = col[i+1];
        }
    }
    if(dist[n-1] > dist[0]+1){
        dist[n-1] = dist[0]+1;
        col[n-1] = col[0];
    }
    REV(i,n-2,0){
        if(dist[i] > dist[i+1]+1){
            dist[i] = dist[i+1]+1;
            col[i] = col[i+1];
        }
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
    
    cin>>n>>k;
    cin>>str;
    
    FOR(i,n){
        int a = i-1, b = i+1;
        if(a < 0)a = n-1;
        if(b == n)b = 0;
        if(str[a] != str[i] && str[b] != str[i]){
            single[i] = true;
            dist[i] = OO;
        }
        col[i] = str[i];
    }
    reflex();
    
    FOR(i,n){
        if(dist[i] == 0)continue;
        if(dist[i] <= k){
            str[i] = col[i];
        }else{
            if(k&1){
                if(str[i] == 'B')str[i] = 'W';
                else str[i] = 'B';
            }
        }
    }
    
    cout << str << endl;
    
    return 0;
}