//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
struct answer{
	vector<pair<pair<int,int>,pair<int,int> > >_v;
	void insert(int a,int b,int c,int d){
		_v.push_back(make_pair(make_pair(a,b),make_pair(c,d)));
	}
	void print(){
		cout<<_v.size()<<endl;
		for(auto _p:_v){
			cout<<_p.first.first<<" "<<_p.first.second<<" "<<_p.second.first<<" "<<_p.second.second<<endl;
		}
	}
}ans;
int n;
int r[1005],c[1005],posr[1005],posc[1005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>r[i],posr[r[i]]=i;
	for(int i=1;i<=n;i++)cin>>c[i],posc[c[i]]=i;
	for(int i=1;i<=n;i++){
		int pr=posr[i],pc=posc[i];
		if(pr==i&&pc==i)continue;
		if(pr==i)ans.insert(i,i,i,pc);
		else if(pc==i)ans.insert(pr,i,i,i);
		else ans.insert(pr,i,i,pc);
		swap(posr[i],posr[r[i]]);
		swap(r[i],r[pr]);
		swap(posc[i],posc[c[i]]);
		swap(c[i],c[pc]);
	}
	ans.print();
	return 0;
}