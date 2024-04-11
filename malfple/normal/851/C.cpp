#include <iostream>
#include <iomanip>
#include <cstdio>

#include <cstring>
#include <string>
#include <sstream>

#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>

#include <queue>
#include <utility>
#include <set>
#include <stack>
#include <vector>
#include <map>

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
#define ff first
#define ss second

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

struct vec5{
    int a,b,c,d,e;
    vec5(int pa=0, int pb=0, int pc=0, int pd=0, int pe=0) : a(pa), b(pb), c(pc), d(pd), e(pe){}
};

vec5 operator+(const vec5& a, const vec5& b){
    return vec5(a.a+b.a, a.b+b.b, a.c+b.c, a.d+b.d, a.e+b.e);
}
vec5 operator-(const vec5& a, const vec5& b){
    return vec5(a.a-b.a, a.b-b.b, a.c-b.c, a.d-b.d, a.e-b.e);
}

int dot(const vec5& a, const vec5& b){
    return a.a*b.a + a.b*b.b + a.c*b.c + a.d*b.d + a.e*b.e;
}

int n;
vec5 arr[N];
bool rekt[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    REP(i,1,n)cin>>arr[i].a>>arr[i].b>>arr[i].c>>arr[i].d>>arr[i].e;

    REP(i,1,n){
        if(rekt[i])continue;
        REP(j,1,n){
            if(i == j)continue;
            arr[j] = arr[j]-arr[i];
        }

        REP(j,1,n){
            if(i == j)continue;
            REP(k,1,n){
                if(i == k)continue;
                if(j == k)continue;

                if(dot(arr[j], arr[k]) > 0){
                    rekt[i] = true;
                }else{
                    rekt[j] = true;
                    rekt[k] = true;
                }
            }
        }

        REP(j,1,n){
            if(i == j)continue;
            arr[j] = arr[j]+arr[i];
        }
    }

    int cnt = 0;
    REP(i,1,n)if(!rekt[i])cnt++;
    cout << cnt << endl;
    REP(i,1,n)if(!rekt[i])cout << i << endl;

    return 0;
}