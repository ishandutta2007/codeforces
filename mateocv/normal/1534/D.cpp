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

ll n; 

vector<ll> ask(ll x){
	cout<<"? "<<x+1<<endl;
	vector<ll> resp(n);
	fore(i,0,n)cin>>resp[i];
	return resp;
}

int main(){FIN;
	cin>>n;
	auto c=ask(0);
	ll cant[2]={0,0};
	fore(i,0,n)cant[c[i]&1]++;
	ll par=0;
	if(cant[1]<cant[0])par=1;
	vector<pair<ll,ll>> res;
	if(par==0){
		fore(i,0,n){
			if(c[i]==1)res.pb({0,i});
		}
	}
	fore(i,1,n){
		if((c[i]&1)==par){
			auto a=ask(i);
			fore(j,0,n){
				if(a[j]==1){
					res.pb({i,j});
				}
			}
		}
	}
	cout<<"!\n";
	for(auto i:res){
		cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	}
	
	return 0;
}