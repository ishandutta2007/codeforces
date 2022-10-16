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

inline void OPTIMIZE(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
}

//end of macro

const int N = 3e5 + 5;
const int H = 18;

int n;
int sparse[H+1][N];

int query(int l, int r){
	if(l > r)return 0;
	int ret = sparse[0][r];
	for(int i=H, jump=(1<<H); i>=0; i--, jump>>=1){
		if(l + jump <= r){
			ret = __gcd(ret, sparse[i][l]);
			l += jump;
		}
	}
	return ret;
}

vi vans;
bool cek(int sz, bool fillans){
	//printf("cek %d\n",sz);
	deque<int>dq;
	REP(i,1,sz-1){
		while(!dq.empty() && sparse[0][dq.back()] >= sparse[0][i])dq.pop_back();
		dq.pb(i);
	}
	bool ret = false;
	REP(i,1,n-sz+1){
		int j = i+sz-1;
		
		if(dq.front() < i)dq.pop_front();
		while(!dq.empty() && sparse[0][dq.back()] >= sparse[0][j])dq.pop_back();
		dq.pb(j);
		
		int mn = sparse[0][dq.front()];
		
		if(query(i,j) == mn){
			ret = true;
			if(fillans){
				vans.pb(i);
			}
		}
	}
	return ret;
}

int main(){
    //OPTIMIZE();
	
	cin>>n;
	REP(i,1,n)cin>>sparse[0][i];
	
	for(int i=1, jump=1; i<=H; i++, jump<<=1){
		REP(j,1,n){
			sparse[i][j] = sparse[i-1][j];
			if(j+jump <= n)sparse[i][j] = __gcd(sparse[i][j], sparse[i-1][j+jump]);
		}
	}
	
	int lo = 1, hi = n, ans = 0;
	while(lo <= hi){
		int mid = (lo+hi)>>1;
		if(cek(mid, false)){
			lo = mid+1;
			ans = mid;
		}else{
			hi = mid-1;
		}
	}
	
	cek(ans, true);
	cout << vans.size() << " " << ans-1 << endl;
	FOR(i,vans.size()){
		cout << vans[i] << " ";
	}cout << endl;
	
	//system("pause");
	
    return 0;
}