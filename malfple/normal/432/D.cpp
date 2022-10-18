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
const int H = 17;

int kmp[N];

int n;
string str; // 0 based ofc
int sparse[H+1][N]; // 0 based as well
int pow2[H+1]; // power of 2
int SA[N]; // 1-based HUE

pair<pii,int> buffer[N], copyy[N];
int cnt[N];

void radix(int sz){ // sorts 0..sz-1 on buffer
	int pclear = 0;
	FOR(i,n)copyy[i] = buffer[i];
	FOR(i,n){
		while(pclear <= buffer[i].F.S)cnt[pclear++] = 0;
		cnt[buffer[i].F.S]++;
	}
	REP(i,1,pclear-1)cnt[i] += cnt[i-1];
	FORD(i,n){
		buffer[--cnt[copyy[i].F.S]] = copyy[i];
	}
	
	pclear = 0;
	FOR(i,n)copyy[i] = buffer[i];
	FOR(i,n){
		while(pclear <= buffer[i].F.F)cnt[pclear++] = 0;
		cnt[buffer[i].F.F]++;
	}
	REP(i,1,pclear-1)cnt[i] += cnt[i-1];
	FORD(i,n){
		buffer[--cnt[copyy[i].F.F]] = copyy[i];
	}
}

void buildSA(){ // from str with length n
	pow2[0] = 1;
	REP(i,1,H)pow2[i] = pow2[i-1]<<1;
	
	FOR(i,n)sparse[0][i] = str[i];
	REP(i,1,H){
		FOR(j,n){
			buffer[j] = mp(mp(sparse[i-1][j], 0), j);
			if(j+pow2[i-1] < n) // 2nd char inside bounds
				buffer[j].F.S = sparse[i-1][j+pow2[i-1]];
		}
		radix(n);
		
		pii prev = mp(-1, -1); int id = 0;
		FOR(j,n){
			if(buffer[j].F != prev){
				prev = buffer[j].F;
				id++;
			}
			sparse[i][buffer[j].S] = id;
		}
	}
	
	FOR(i,n){
		SA[sparse[H][i]] = i;
	}
}

int LCP(int a, int b){
	int ret = 0;
	REV(i,H,0){
		if(sparse[i][a] == sparse[i][b]){
			ret += pow2[i];
			a += pow2[i];
			b += pow2[i];
		}
	}
	return ret;
}

vii ans;

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    #define endl '\n'
    
    cin>>str;
    n = str.size();
    
    //cout << str << " " << str2 << endl;
    
	kmp[0] = -1;	
	for(int i=0, j=-1; i < str.size(); i++, j++){
	    while ((j >= 0) && (str[i] != str[j])) j = kmp[j];
	    kmp[i+1] = j+1;
	}
	
	buildSA();
	//REP(i,1,n)cout << SA[i] << endl;
	
	int bottom = sparse[H][0];
	for(int now = n; now > 0; now = kmp[now]){
		while(bottom <= n && LCP(n-now, SA[bottom]) >= now){
			bottom++;
		}
		ans.pb(mp(now, bottom - sparse[H][n-now]));
	}
	
	cout << ans.size() << endl;
	reverse(ans.begin(), ans.end());
	FOR(i,ans.size()){
		cout << ans[i].F << " " << ans[i].S << endl;
	}
    
    return 0;
}