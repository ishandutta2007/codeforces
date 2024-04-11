#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
#define sz size()

//===================//
//  Added libraries  //
//===================//

// mod library
ll MOD=1e9+7;

inline ll mod(ll x_) {
	return (x_)%MOD;
}
ll modpow(ll x_, ll N_) {
    if(N_ == 0) return 1;
    ll a = modpow(x_,N_/2);
    a = (a*a)%MOD;
    if(N_%2) a = (a*x_)%MOD;
    return a;
}
ll inv(ll x_) {
    return modpow(x_, MOD-2);
}
class mi {
public:
    mi(ll v=0) {value = v;}
    mi  operator+ (ll rs) {return mod(value+rs);}
    mi  operator- (ll rs) {return mod(value-rs+MOD);}
    mi  operator* (ll rs) {return mod(value*rs);}
    mi  operator/ (ll rs) {return mod(value*inv(rs));}
    mi& operator+=(ll rs) {*this = (*this)+rs; return *this;}
    mi& operator-=(ll rs) {*this = (*this)-rs; return *this;}
    mi& operator*=(ll rs) {*this = (*this)*rs; return *this;}
    mi& operator/=(ll rs) {*this = (*this)/rs; return *this;}
    operator ll&() {return value;}

    ll value;
};
typedef vector<mi> vmi;

//===================//
//end added libraries//
//===================//

void program();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	program();
}


//===================//
//   begin program   //
//===================//

const int MX = 5e5, BITS=20, BM=(1<<BITS);
int n, q, a[MX];
priority_queue<ii,vii,greater<ii>> pq;
int ans[MX], l[MX], x[MX];
int basis[BITS], cnt=0;

void addBasis(int y) {
    RE(i,BITS) {
        if((y&(1<<i))==0) continue;
        if(!basis[i]) {
            basis[i] = y;
            cnt++;
            return;
        }
        y ^= basis[i];
    }
}
bool canMake(int y) {
    RE(i,BITS) {
        if((y&(1<<i))==0) continue;
        if(!basis[i])
            return 0;
        y ^= basis[i];
    }
    return 1;
}

void program() {
    cin>>n>>q;
    RE(i,n) cin>>a[i];
    RE(i,q) {
        cin>>l[i]>>x[i];
        pq.push({l[i],i});
    }
    RE(i,BITS) basis[i]=0;
    int i=0;
    while(!pq.empty()) {
        ii p = pq.top(); pq.pop();
        while(i < p.first) {
            addBasis(a[i]);
            i++;
        }
        if(canMake(x[p.se])) {
            ans[p.se] = modpow(2,p.fi-cnt);
        } else {
            ans[p.se] = 0;
        }
    }
    RE(j,q) cout<<ans[j]<<endl;
}