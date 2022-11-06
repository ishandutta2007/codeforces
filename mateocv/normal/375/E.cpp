#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

double EPS=1e-9;
vector<int> X,Y;
vector<vector<double> > A;
vector<double> b,c;
double z;
int n,m;
void pivot(int x,int y){
	swap(X[y],Y[x]);
	b[x]/=A[x][y];
	fore(i,0,m)if(i!=y)A[x][i]/=A[x][y];
	A[x][y]=1/A[x][y];
	fore(i,0,n)if(i!=x&&abs(A[i][y])>EPS){
		b[i]-=A[i][y]*b[x];
		fore(j,0,m)if(j!=y)A[i][j]-=A[i][y]*A[x][j];
		A[i][y]=-A[i][y]*A[x][y];
	}
	z+=c[y]*b[x];
	fore(i,0,m)if(i!=y)c[i]-=c[y]*A[x][i];
	c[y]=-c[y]*A[x][y];
}
pair<double,vector<double> > simplex( // maximize c^T x s.t. Ax<=b, x>=0
		vector<vector<double> > _A, vector<double> _b, vector<double> _c){
	// returns pair (maximum value, solution vector)
	A=_A;b=_b;c=_c;
	n=b.size();m=c.size();z=0.;
	X=vector<int>(m);Y=vector<int>(n);
	fore(i,0,m)X[i]=i;
	fore(i,0,n)Y[i]=i+m;
	while(1){
		int x=-1,y=-1;
		double mn=-EPS;
		fore(i,0,n)if(b[i]<mn)mn=b[i],x=i;
		if(x<0)break;
		fore(i,0,m)if(A[x][i]<-EPS){y=i;break;}
		if(y<0){
			return {-1,{}};
		}
		assert(y>=0); // no solution to Ax<=b
		pivot(x,y);
	}
	while(1){
		double mx=EPS;
		int x=-1,y=-1;
		fore(i,0,m)if(c[i]>mx)mx=c[i],y=i;
		if(y<0)break;
		double mn=1e200;
		fore(i,0,n)if(A[i][y]>EPS&&b[i]/A[i][y]<mn)mn=b[i]/A[i][y],x=i;
		assert(x>=0); // c^T x is unbounded
		pivot(x,y);
	}
	vector<double> r(m);
	fore(i,0,n)if(Y[i]<m)r[Y[i]]=b[i];
	return {z,r};
}

const int MAXN=505;

vector<pair<ll,ll>> g[505];
ll dist[MAXN];
void dijkstra(int x){
	memset(dist,-1,sizeof(dist));
	priority_queue<pair<ll,int> > q;
	dist[x]=0;q.push({0,x});
	while(!q.empty()){
		x=q.top().snd;ll c=-q.top().fst;q.pop();
		if(dist[x]!=c)continue;
		fore(i,0,g[x].size()){
			int y=g[x][i].fst; ll c=g[x][i].snd;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push({-dist[y],y});
		}
	}
}

set<ll> vec[505];

int main(){FIN;
	ll n,x; cin>>n>>x;
	ll col[n];
	fore(i,0,n)cin>>col[i];
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--; v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	fore(i,0,n){
		dijkstra(i);
		fore(j,0,n){
			if(dist[j]<=x&&dist[j]>=0){
				vec[i].insert(j);
			}
		}
	}
	fore(i,0,n){
		vector<double> v;
		fore(j,0,n){
			if(vec[i].count(j))v.pb(-1);
			else v.pb(0);
		}
		A.pb(v); b.pb(-1);
	}
	fore(i,0,n){
		vector<double> v;
		fore(j,0,n){
			v.pb(i==j);
		}
		A.pb(v); b.pb(1);
	}
	ll cant=0;
	fore(i,0,n)cant+=col[i];
	vector<double> v;
	fore(i,0,n)v.pb(1);
	A.pb(v); b.pb(cant);
	fore(i,0,n)v[i]=-1;
	A.pb(v); b.pb(-cant);
	fore(i,0,n)c.pb(col[i]);
/*	fore(i,0,SZ(A)){
		fore(j,0,SZ(A[i]))cout<<A[i][j]<<" ";
		cout<<b[i]<<"\n";
	}*/
	auto res=simplex(A,b,c);
	if(res.fst<0)cout<<-1;
	else cout<<cant-res.fst;
	//for(auto i:res.snd)cout<<i<<" ";
	return 0;
}