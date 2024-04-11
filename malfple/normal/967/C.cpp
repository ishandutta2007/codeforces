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

const int N = 1e5 + 5;

int n,m,v;
int ladd[N];
int elev[N];
int q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>n>>m>>v;
    REP(i,1,n)cin>>ladd[i];
    REP(i,1,m)cin>>elev[i];
    cin>>q;
    REP(i,1,q){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1 > x2)swap(x1, x2);
        if(y1 > y2)swap(y1, y2);
        if(x1 == x2){
            cout << y2-y1 << endl;
            continue;
        }
        int useladd = 0, useelev = 0;
        int p1, p2;
        p1 = lower_bound(ladd+1, ladd+n+1, y1)-ladd;
        p2 = lower_bound(ladd+1, ladd+n+1, y2)-ladd;
        if(p1 == p2){
            useladd = OO;
            if(p1 > 1){
                useladd = min(useladd, 2*(y1-ladd[p1-1]));
            }
            if(p2 <= n){
                useladd = min(useladd, 2*(ladd[p2]-y2));
            }
        }
        p1 = lower_bound(elev+1, elev+m+1, y1)-elev;
        p2 = lower_bound(elev+1, elev+m+1, y2)-elev;
        if(p1 == p2){
            useelev = OO;
            if(p1 > 1){
                useelev = min(useelev, 2*(y1-elev[p1-1]));
            }
            if(p2 <= m){
                useelev = min(useelev, 2*(elev[p2]-y2));
            }
        }
        useladd += y2-y1;
        useelev += y2-y1;
        useladd += x2-x1;
        useelev += (x2-x1)/v + (((x2-x1)%v) ? 1 : 0);
        //printf("%d %d\n",useladd, useelev);
        cout << min(useladd, useelev) << endl;
    }

    return 0;
}