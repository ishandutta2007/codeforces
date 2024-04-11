#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

const int MXN = 251;
int dx[]={0,0,1,-1}, dy[]={-1,1,0,0};
bool g[MXN][MXN];
ll N, M, Q, P, m[MXN][MXN];
bitset<63500> vis;

void bfs(int xs, int ys, ll ival){
	queue<pair<pair<int,int>,int> > q; q.push({{xs,ys},ival}); vis.reset();
	vis[xs*M+ys]=1;
	while(!q.empty()){
		pair<int,int> u=q.front().first;
		ll d=q.front().second; q.pop();
		if(d==0)break;
		m[u.first][u.second] += d;
		fore(i,0,4){
			pair<int,int> v={u.first+dx[i],u.second+dy[i]};
			if(v.first<N && v.first>=0 && v.second<M && v.second>=0 && g[v.first][v.second] && !vis[v.first*M+v.second]){
				vis[v.first*M+v.second]=1; q.push({v,d/2});
			}
		}
	}
}
vector<pair<int,int> > A[26];

int main(){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> Q >> P;
	fore(x,0,N) fore(y,0,M){
		char c; cin >> c;
		if(c>='A' && c<='Z')A[c-'A'].pb({x,y});
		g[x][y]=c!='*';
	}
	fore(x,0,26) for(auto p : A[x])
		bfs(p.first,p.second,(x+1)*Q);
	int cnt=0;
	fore(x,0,N) fore(y,0,M)
		cnt += m[x][y] > P;
	cout << cnt << "\n";
	return 0;
}