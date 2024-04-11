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

ll a,b,c;
ll xa,ya,xb,yb;

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>a>>b>>c;
    cin>>xa>>ya>>xb>>yb;
    if(a==0 || b==0){
        cout << abs(xa-xb)+abs(ya-yb) << endl;
    }else{
        double ans = abs(xa-xb)+abs(ya-yb);
        REP(i,1,2){
            double x1,y1;
            if(i == 1){
                x1 = xa;
                y1 = (double)(-a*x1-c)/b;
            }else{
                y1 = ya;
                x1 = (double)(-b*y1-c)/a;
            }
            REP(j,1,2){
                double x2,y2;
                if(j == 1){
                    x2 = xb;
                    y2 = (double)(-a*x2-c)/b;
                }else{
                    y2 = yb;
                    x2 = (double)(-b*y2-c)/a;
                }
                ans = min(ans, dist(xa,ya,x1,y1) + dist(x1,y1,x2,y2) + dist(x2,y2,xb,yb));
            }
        }
        cout << ans << endl;
    }

    return 0;
}