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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//===================//
//  Added libraries  //
//===================//

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

const int BIT=18, MX=1<<BIT;
int n;
int a[MX];
int r[MX], p[MX];
vii nodes[MX];
int cnt[MX];

int getSet(int i) {return i==p[i] ? i : p[i]=getSet(p[i]);}
bool isSameSet(int i, int j) {return getSet(i)==getSet(j);}
void unionSet(int i, int j) {
	if(!isSameSet(i,j)) {
		i=getSet(i), j=getSet(j);
		if(r[i] > r[j]) {
			p[j] = i;
		} else {
			p[i] = j;
			if(r[i] == r[j]) r[j]++;
		}
	}
}

void program() {
	cin>>n;
	RE(i,n) cin>>a[i];
	a[n++] = 0;
	RE(i,MX) cnt[i] = 0;
	RE(i,n) cnt[a[i]]++;
	RE(i,MX) r[i] = 0, p[i]=i;
	ll ans=0;
	RE(i,n) ans -= a[i];
	REV(i,0,MX) {
		for(int j=i; ; j=(j-1)&i) {
			int k=i^j;
			if(cnt[j] && cnt[k] && !isSameSet(j,k)) {
				unionSet(j,k);
				ans += ll(i)*ll(cnt[j]+cnt[k]-1);
				cnt[j] = 1;
				cnt[k] = 1;
			}
			if(j == 0) break;
		}
	}
	cout<<ans<<endl;
}