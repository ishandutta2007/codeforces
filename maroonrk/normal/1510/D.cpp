#include <bits/stdc++.h>
using namespace std;

using ll=long long;

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u>bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u>bool chmin(t&a,u b){if(a>b){a=b;return true;}else return false;}

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>&p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t>
ostream&operator<<(ostream&os,const vector<t>&v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

using P=pair<int,int>;

template<class t>
using vc=vector<t>;

using vi=vc<int>;

using ld=__float128;
const ld inf=ld(1)/0;

const int nmax=100010;
int a[nmax];
ld w[nmax],dp[nmax][10];
int pre[nmax][10];

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,d;cin>>n>>d;
	rep(i,n){
		cin>>a[i];
		//w[i]=logl(a[i]);
	}
	sort(a,a+n);
	rep(i,n){
		w[i]=logl(a[i]);
	}
	
	rep(j,10)dp[0][j]=-inf;
	dp[0][1]=0;
	rep(i,n){
		rep(j,10){
			dp[i+1][j]=dp[i][j];
			pre[i+1][j]=-1;
		}
		rep(j,10)if(dp[i][j]>=0){
			int k=(j*a[i])%10;
			if(chmax(dp[i+1][k],dp[i][j]+w[i])){
				pre[i+1][k]=j;
			}
		}
	}
	
	if(dp[n][d]<0){
		cout<<-1<<endl;
	}else{
		vi ans;
		int cur=d;
		per(i,n){
			if(pre[i+1][cur]!=-1){
				ans.pb(a[i]);
				cur=pre[i+1][cur];
			}
		}
		if(ans.empty()){
			rep(i,n)if(a[i]==1)ans.pb(1);
		}
		if(ans.empty()){
			cout<<-1<<endl;
			return 0;
		}
		sort(all(ans));
		cout<<si(ans)<<endl;
		for(auto v:ans)cout<<v<<" ";
		cout<<endl;
	}
}