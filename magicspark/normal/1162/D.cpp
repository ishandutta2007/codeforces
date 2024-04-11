#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m;
vector<pair<int,int> >v;
void solve(int x){
	vector<pair<int,int> >nv;
	for(auto p:v){
		int a=p.first+x,b=p.second+x;
		if(a>n)a-=n;if(b>n)b-=n;
		nv.push_back(make_pair(min(a,b),max(a,b)));
	}
	sort(nv.begin(),nv.end());
	if(nv==v){
		puts("yES");
		exit(0);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	while(m--){
		int a,b;cin>>a>>b;
		v.push_back(make_pair(min(a,b),max(a,b)));
	}
	sort(v.begin(),v.end());
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
		//	cerr<<i<<" "<<n/i<<endl;
			solve(i);
			if(i!=1)solve(n/i);
		}
	}
	puts("nO");
	return 0;
}