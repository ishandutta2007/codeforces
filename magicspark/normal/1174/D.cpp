#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,x;
set<pair<int,int> >S;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>x;int mask=(1<<18)-1;
	for(int i=1;i<(1<<18);i++){
		if(i!=x)S.insert(make_pair(min(i,i^x),max(i,i^x)));
	}
	vector<pair<int,int> >vec(S.begin(),S.end());
	vector<int>pre;
	pre.push_back(0);
	for(auto p:S){
		if(p.first<(1<<n)){
			pre.push_back(p.first);
//			cerr<<p.first<<" "<<p.second<<endl;
		}
	}
	cout<<pre.size()-1<<endl;
	for(int i=1;i<pre.size();i++)cout<<(pre[i]^pre[i-1])<<" ";
	return 0;
}