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

const int N = 5205;

int n;
bitset<N>arr[N];
int from[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    
    cin>>n;
    FOR(i,n){
        string str;
        cin>>str;
        FOR(j,str.size()){
            int x;
            if(str[j] >= '0' && str[j] <= '9')x = str[j]-'0';
            else x = 10 + str[j]-'A';
            FORD(k,4){
                arr[i][j*4+k] = x&1;
                x>>=1;
            }
        }
        //cout << arr[i] << endl;
    }
    
    int ans = 1;
    REP(x,2,n)from[x] = 1;
    REP(x,2,n){
        if(from[x] == -1)continue;
        if(n%x == 0){
            bool fail = false;
            REPP(i,0,n-1,from[x]){
                REPP(j,0,n-1,from[x]){
                    if(arr[i][j] != arr[i/x*x][j/x*x]){
                        fail = true;
                        goto hell;
                    }
                }
            }
            hell:;
            if(!fail){
                ans = x;
                REPP(i,x,n,x){
                    if(from[i] != -1)from[i] = x;
                }
            }else{
                REPP(i,x,n,x){
                    from[i] = -1;
                }
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}

/*
4
C
C
0
0

4
0
0
0
0
*/