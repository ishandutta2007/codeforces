#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second

const int MAXN=3005;
const ll INF=1e10;
ll n,p,s,dp[MAXN][MAXN],sum[MAXN][MAXN];
vector<vector<int>>a;// a,b,indice
vector<int>aa,bb;


ll get_sum(int i,int j) {
	if(j==0)return 0;
	if(i==n)return -INF;
	if(sum[i][j]!=-1)return sum[i][j];
	//cout<<"getting sum: "<<i<<" "<<j<<endl;
	return sum[i][j]=max(get_sum(i+1,j),a[i][1]+get_sum(i+1,j-1));
}
ll solve(int i,int j) {
	if(j==p)return get_sum(i,s-(i-p));
	if((i-j)>s)return -INF;
	if(dp[i][j]!=-1)return dp[i][j];
	//cout<<"solving: "<<i<<" "<<j<<endl;
	ll res=a[i][1]+solve(i+1,j);
	res=max(res,a[i][0]+solve(i+1,j+1));
	return dp[i][j]=res;
}

void build_sum(int i,int j) {
	//cout<<"building sum: "<<i<<" "<<j<<" "<<endl;
	if(!j)return;
	ll x=get_sum(i+1,j);
	ll y=a[i][1]+get_sum(i+1,j-1);
	if(x>y) {
		build_sum(i+1,j);
	} else {
		bb.pb(a[i][2]);
		build_sum(i+1,j-1);
	}
}

void build(int i,int j) {
	//cout<<"building: "<<i<<" "<<j<<endl;
	if(j==p){
		build_sum(i,s-(i-p));
		return;
	}
	ll x=a[i][0]+solve(i+1,j+1);
	ll y=a[i][1]+solve(i+1,j);
	if(x>y) {
		aa.pb(a[i][2]);
		build(i+1,j+1);
	} else {
		bb.pb(a[i][2]);
		build(i+1,j);
	}
	
}

int main() {FIN;
	memset(dp,-1,sizeof(dp));
	memset(sum,-1,sizeof(sum));
	cin>>n>>p>>s;
	fore(i,0,n){
		int x;cin>>x;
		a.pb({x,-1,i+1});
	}
	fore(i,0,n)cin>>a[i][1];
	sort(a.begin(),a.end(),greater<vector<int>>());
	cout<<solve(0,0)<<endl;
	//cout<<"done solve"<<endl;
	build(0,0);
	for(auto it:aa)cout<<it<<" ";cout<<endl;
	for(auto it:bb)cout<<it<<" ";cout<<endl;
}