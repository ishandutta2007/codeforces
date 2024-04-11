#include <bits/stdc++.h>
using namespace std;

using ll=long long;
//#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=a;i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(a>b)a=b;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

struct arr{
	int n,t;
	vi a,b;
	arr(int nn):n(nn),t(0),a(n),b(n){}
	void cl(){t++;}
	int&operator[](int i){
		if(b[i]<t){
			a[i]=-1;
			b[i]=t;
		}
		return a[i];
	}
};

void slv(){
	int n,q;cin>>n>>q;
	vvc<int> a(q);
	rep(i,q){
		int k;cin>>k;
		a[i].resize(k);
		rep(j,k){cin>>a[i][j];a[i][j]--;}
	}
	arr w(n);
	sort(all(a),[](const vi&x,const vi&y){return x.size()<y.size();});
	const int V=500;
	while(a.size()&&a.back().size()>=V){
		vi b=a.back();a.pop_back();
		w.cl();
		rep(i,b.size())
			w[b[i]]=i;
		for(const auto&c:a){
			int last=-1,pre=n;
			for(auto i:c){
				if(w[i]==-1){
					//do nothing
				}else{
					if(w[i]<pre){
						pre=w[i];
					}else if(last!=-1&&last+1==w[i]){
						//do nothing
					}else{
						cout<<"Human\n";
						return;
					}
				}
				last=w[i];
			}
		}
	}
	
	vvc<pi> idx(n);
	rep(i,a.size())
		rep(j,int(a[i].size())-1)
			idx[a[i][j]].eb(i,j);
	
	rep(i,n){
		w.cl();
		for(auto p:idx[i]){
			int z=a[p.a][p.b+1];
			rng(jj,p.b+1,a[p.a].size()){
				int j=a[p.a][jj];
				if(w[j]==-1)w[j]=z;
				if(w[j]!=z){
					cout<<"Human\n";
					return;
				}
			}
		}
	}
	
	cout<<"Robot\n";
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int t;cin>>t;
	rep(_,t)slv();
}