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

const int N = 55;

int n,k;
int arr[5][N];

vector<pair<int,pii> >ans;

pii next(pii prev){
	if(prev.F == 2){
		if(prev.S == n){
			prev.F = 3;
		}else{
			prev.S++;
		}
	}else if(prev.F == 3){
		if(prev.S == 1){
			prev.F = 2;
		}else{
			prev.S--;
		}
	}
	return prev;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    
    bool rekt = true;
    
    cin>>n>>k;
    REP(i,1,4){
    	REP(j,1,n){
    		cin>>arr[i][j];
    		if((i == 2 || i == 3) && arr[i][j] == 0){
    			rekt = false;
			}
		}
	}
	
	if(rekt){
		REP(j,1,n){
			if(arr[2][j] == arr[1][j]){
				rekt = false;
				break;
			}
			if(arr[3][j] == arr[4][j]){
				rekt = false;
				break;
			}
		}
	}
	if(rekt){
		cout << -1 << endl;
		return 0;
	}
	
	while(1){
		bool finish = true;
		// insert
		REP(j,1,n){
			if(arr[1][j] != 0 && arr[1][j] == arr[2][j]){
				ans.pb(mp(arr[2][j], mp(1,j)));
				arr[2][j] = 0;
			}
			if(arr[4][j] != 0 && arr[4][j] == arr[3][j]){
				ans.pb(mp(arr[3][j], mp(4,j)));
				arr[3][j] = 0;
			}
			
			if(arr[2][j] != 0 || arr[3][j] != 0){
				finish = false;
			}
		}
		
		if(finish)break;
		
		// rotate
		// find vacant
		pii vacant;
		REP(i,2,3){
			REP(j,1,n){
				if(arr[i][j] == 0){
					vacant = mp(i,j);
					goto hell;
				}
			}
		}
		hell:;
		
		pii prev = vacant;
		while(1){
			pii now = next(prev);
			if(now == vacant)break;
			if(arr[now.F][now.S] != 0){
				ans.pb(mp(arr[now.F][now.S], mp(prev.F, prev.S)));
				swap(arr[now.F][now.S], arr[prev.F][prev.S]);
			}
			prev = now;
		}
	}
	cout << ans.size() << endl;
	FOR(i,ans.size()){
		cout << ans[i].F << " " << ans[i].S.F << " " << ans[i].S.S << endl;
	}

    return 0;
}