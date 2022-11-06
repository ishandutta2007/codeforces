#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200010
#define MOD 998244353
#define INF (ll)1e+18
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;


int main() {
	int n;
	int a[N];
	rep(i,N)a[i]=-1;
	int b[N];
	string str;
	vector<int>res;
	vector<int>d;
	int m;
	vector<int> c[2];
	int sz[2];

	cin >> n;
	rep2(i,1,n)a[i]=0;
	while(true){
		c[0].clear();
		c[1].clear();
		d.clear();
		rep2(i,1,n){
			if(a[i]==0)c[0].pb(i);
			if(a[i]==1)c[1].pb(i);
			if(a[i]>=0)d.pb(i);
		}
		sz[0]=c[0].size();
		sz[1]=c[1].size();
		m=d.size();
		if(m==1){
			cout<<"! "<<d[0]<<endl;
			cout.flush();
			cin>>str;
			return 0;
		}
		if(m==2){
			cout<<"! "<<d[0]<<endl;
			cout.flush();
			cin>>str;
			if(str[1]=='('){
				cout<<"! "<<d[1]<<endl;
				cout.flush();
				cin>>str;				
			}
			return 0;			
		}
		if((m==3)&&(sz[0]==2)){
			cout<<"? 2 "<<c[0][0]<<" "<<c[0][1]<<endl;
			cout.flush();
			cin>>str;
			if(str=="YES"){
				a[c[1][0]]=-1;
				continue;
			}
			else{
				a[c[0][0]]=1;
				a[c[0][1]]=1;
				a[c[1][0]]=0;
				continue;
			}
		}
		res.clear();
		rep(i,(sz[0]+1)/2)res.pb(c[0][i]);
		rep(i,sz[1]/2)res.pb(c[1][i]);
		m=res.size();
		cout<<"? "<<m;
		rep(i,m)cout<<" "<<res[i];
		cout<<endl;
		cout.flush();
		cin>>str;
		if(str=="YES"){
			rep(i,sz[0]){
				if(i<((sz[0]+1)/2))a[c[0][i]]=0;
				else a[c[0][i]]=1;
			}
			rep(i,sz[1]){
				if(i<(sz[1]/2))a[c[1][i]]=0;
				else a[c[1][i]]=-1;
			}
		}
		else{
			rep(i,sz[0]){
				if(i<((sz[0]+1)/2))a[c[0][i]]=1;
				else a[c[0][i]]=0;
			}
			rep(i,sz[1]){
				if(i<(sz[1]/2))a[c[1][i]]=-1;
				else a[c[1][i]]=0;
			}			
		}
	}
    
	return 0;
}