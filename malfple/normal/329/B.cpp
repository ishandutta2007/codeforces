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

const int N = 1005;
const int cx[] = {0,1,0,-1};
const int cy[] = {1,0,-1,0};

int n,m;
char grid[N][N];

queue<pii>q;
bool vis[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    
    cin>>n>>m;
    REP(i,1,n){
    	REP(j,1,m){
    		cin>>grid[i][j];
    		if(grid[i][j] == 'E'){
				q.push(mp(i,j));
				vis[i][j] = true;
			}
		}
	}
	
	int ans = 0;
	for(int qs = q.size(); !q.empty(); qs = q.size()){
		bool found = false;
		FOR(x,qs){
			int nx = q.front().F;
			int ny = q.front().S;
			q.pop();
			
			if(grid[nx][ny] == 'S')found = true;
			else if(grid[nx][ny] >= '1' && grid[nx][ny] <= '9')ans += grid[nx][ny]-'0';
			
			FOR(k,4){
				int tx = nx + cx[k];
				int ty = ny + cy[k];
				if(tx < 1 || tx > n || ty < 1 || ty > m)continue;
				if(grid[tx][ty] == 'T')continue;
				if(vis[tx][ty])continue;
				vis[tx][ty] = true;
				q.push(mp(tx,ty));
			}
		}
		
		if(found)break;
	}
	
	cout << ans << endl;
    
    return 0;
}