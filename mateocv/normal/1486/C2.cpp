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

ll q=20;

ll ask(ll l, ll r){
	if(l==r)return -1;
	q--;
	assert(q>=0);
	cout<<"? "<<l+1<<" "<<r+1<<endl;
	ll resp;
	cin>>resp; resp--;
	return resp;
}

int main(){FIN;
	ll n; cin>>n;
	ll p=ask(0,n-1);
	ll d=-1;
	if(p>0)d=ask(0,p);
	if(d==p){
		ll l=0,r=p;
		while(l<=r){
			ll m=(l+r)/2;
			if(ask(m,p)==p)l=m+1;
			else r=m-1;
		}
		cout<<"! "<<r+1<<endl;
	}else{
		ll l=p,r=n-1;
		while(l<=r){
			ll m=(l+r)/2;
			if(ask(p,m)==p)r=m-1;
			else l=m+1;
		}
		cout<<"! "<<l+1<<endl;
	}
	
	return 0;
}