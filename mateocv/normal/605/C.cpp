#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
#define mset(a,v) memset(a,v,sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
 
double EPS=1e-8;
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
 
int main(){FIN;
	ll n,p,q; cin>>n>>p>>q;
	vector<double> a,b;
	ll lle,lle2;
	fore(i,0,n)cin>>lle>>lle2,a.pb(-lle),b.pb(-lle2);
	vector<vector<double>> A;
	A.pb(a); A.pb(b);
	vector<double> B={-p,-q};
	vector<double> c;
	fore(i,0,n)c.pb(-1);
	/*for(auto i:A){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	for(auto i:B)cout<<i<<" ";cout<<endl;*/
	auto res=simplex(A,B,c);
	cout<<fixed<<setprecision(10)<<-res.fst;
}