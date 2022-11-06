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

ll ask(ll a, ll b){
	cout<<"? "<<a+1<<" "<<b+1<<endl;
	ll res; cin>>res;
	assert(res!=0);
	return res;
}

int main(){FIN;
	vector<pair<ll,ll>> q;
	fore(i,0,50){
		fore(j,0,i){
			q.pb({i,j});
		}
	}
	fore(i,0,25){
		ll a=ask(q[i].fst,q[i].snd);
		ll b=ask(q[i].snd,q[i].fst);
		if(a==-1||b==-1){
			cout<<"! "<<q[i].fst<<endl;
			return 0;
		}
		if(a!=b){
			cout<<"! "<<a+b<<endl;
			return 0;
		}
	}
	cout<<"! 3"<<endl;
	return 0;
}