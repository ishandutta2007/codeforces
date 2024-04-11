#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN=1e5+10;
int n,k;
int a[MAXN];
double dp[MAXN][11];
int vis[MAXN][11],INF=1e9;

double solve(int pos, int rem){
	if(pos==n) return rem==k?0:-INF;
	double &r=dp[pos][rem];
	if(vis[pos][rem]) return r;
	vis[pos][rem]=1;
	
	int nr=rem==10?a[pos]%10:rem*a[pos]%10;
	r=max(solve(pos+1,rem),log(a[pos])+solve(pos+1,nr));
	return r;
}

bool eq(double x, double y){
	return abs(x-y)<1e-8;
}

int main(){FIN;
	cin>>n>>k;
	fore(i,0,n) cin>>a[i];
	sort(a,a+n); reverse(a,a+n);
	
	if(solve(0,10)<0) cout<<"-1\n",exit(0);
	
	int pos=0,rem=10;
	vector<int> ans;
	while(pos<n){
		int nr=rem==10?a[pos]%10:rem*a[pos]%10;
		if(eq(log(a[pos])+solve(pos+1,nr),solve(pos,rem))) ans.pb(a[pos]), rem=nr;
		pos++;
	}
	
	sort(ALL(ans));
	cout<<SZ(ans)<<"\n";
	for(auto x:ans)cout<<x<<" ";cout<<"\n";
}