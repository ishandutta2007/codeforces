#include <bits/stdc++.h>
using namespace std;

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

//===================//
//  Added libraries  //
//===================//

// sparse library
constexpr size_t _LOG2(size_t _X) {return _X < 2 ? 0 : 1 + _LOG2(_X/2);}
int LOG2(int _X) {return _X < 2 ? 0 : 1 + LOG2(_X/2);}

template<size_t SIZE, class T>
class Sparse {
public:
	void build(T values[], int size, function<T(T,T)> func) {
		sz	= size;
		f	= func;
		for(int i=0; i!=sz; i++)
			a[i][0] = values[i];
		for(int j=1; (1<<j)<=sz; j++)
			for(int i=0; i+(1<<j)-1<sz; i++)
				a[i][j] = f(a[i][j-1], a[i+(1<<(j-1))][j-1]);
	}
	T query(int i, int j) {
		if(j < i) swap(i,j);
		int k = LOG2(j-i+1);
		return f(a[i][k], a[j-(1<<k)+1][k]);
	}

private:
	int a[SIZE][_LOG2(SIZE)];
	int sz;
	function<T(T,T)> f;
};


//===================//
//end added libraries//
//===================//

void program();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	program();
}



//===================//
//   begin program   //
//===================//

const int MX=2100, MOD=1e9+7, LOG=15;
int n, a[2], p[2][MX], x[2][MX];
int dp[2][MX][MX];
int BEG[2][MX], END[2][MX], d[2][MX];
vi chl[2][MX];
int cntBeg[2][MX], cntEnd[2][MX];
int H[2][MX], E[2][MX*2], idx[2];
Sparse<MX*2, int> spt[2];

void dfs(bool s, int v, int depth=0) {
	d[s][v] = depth;
	for(int u:chl[s][v]) {
		dfs(s, u, depth+1);
		BEG[s][v] = min(BEG[s][v], BEG[s][u]);
		END[s][v] = max(END[s][v], END[s][u]);
		cntBeg[s][BEG[s][u]]++;
		cntEnd[s][END[s][u]]++;
	}
}
void dfsLCA(bool s, int v) {
	H[s][v] = idx[s];
	E[s][idx[s]++] = v;
	for(int u:chl[s][v]) {
		dfsLCA(s, u);
		E[s][idx[s]++] = v;
	}
}
int lca(bool s, int u, int v) {
	return spt[s].query(H[s][u], H[s][v]);
}
int getCost(bool s, int b, int e, int last) {
	int ans = cntBeg[s][e] - (b == 0 ? 0 : cntEnd[s][b-1]) - (last == 0 ? 0 : d[s][lca(s,x[s][last-1],x[s][b])]);
	return ans;
}
int DP(bool side, int i, int j) {
	if(j == n) return 0;
	if(dp[side][i][j] == -1) {
		int ans=INF;
		REP(k,j,n) {
			ans = min(ans, getCost(side,j,k,i) + DP(!side,j,k+1));
		}
		dp[side][i][j] = ans;
	}
	return dp[side][i][j];
}

void program() {
    cin>>n;

    RE(j,2) {
	    cin>>a[j];
	    RE(i,a[j]-1) cin>>p[j][i+1], p[j][i+1]--; p[j][0]=-1;
	    RE(i,a[j]-1) chl[j][p[j][i+1]].pb(i+1);
	    RE(i,a[j]) BEG[j][i]=INF, END[j][i]=0;
	    RE(i,n) cin>>x[j][i], x[j][i]--;
	    RE(i,n) BEG[j][x[j][i]]=i, END[j][x[j][i]]=i;
    	
    	RE(i,n) cntBeg[j][i]=cntEnd[j][i]=0;
    	dfs(j,0);
    	REP(i,1,n) cntBeg[j][i] += cntBeg[j][i-1];
    	REP(i,1,n) cntEnd[j][i] += cntEnd[j][i-1];
    	dfsLCA(j,0);
    	spt[j].build(E[j], idx[j], [=](int u, int v) {
    		return d[j][u] < d[j][v] ? u : v;
    	});
    }
    int minAns[2][MX];
    RE(i,n+1) minAns[0][i]=minAns[1][i]=INF;
    REV(j,0,n+1) REV(i,0,j+1) RE(s,2) {
		int ans=minAns[s][j];
		ans -= (j == 0 ? 0 : cntEnd[s][j-1]) + (i == 0 ? 0 : d[s][lca(s,x[s][i-1],x[s][j])]);
		if(j == n) ans = 0;
		dp[s][i][j] = ans;
		if(j != 0)
			minAns[!s][i] = min(minAns[!s][i], cntBeg[!s][j-1] + dp[s][i][j]);
    }
    cout << a[0]+a[1]-min(dp[0][0][0], dp[1][0][0])-2 << endl;
}