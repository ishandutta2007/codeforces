#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){
	if(a*b==0){
		return a+b;
	}
	return __gcd(a,b);
}

int main(){FIN;
	ll n; cin>>n;
	ll l=1,r=1ll*1e9,m,resp,cont=0;
	while(l <= r) {
		m = (l+r)/2;
		if(cont<60){
			cout<<"> "<<m<<endl;
			cont++;
			cin>>resp; 
			if(resp==-1)return 0;
			if(resp) l=m+1;
			else r=m-1;	
		}
	}//usar l
	//cout<<cont<<" "<<l;
	vector<ll> v;
	srand(time(NULL));
	while(cont<60){
		cout<<"? "<<(((rand()<<15)+rand())%n)+1<<endl;
		cont++;
		cin>>resp;
		if(resp==-1)return 0;
		v.pb(resp);
	}
	sort(ALL(v));
	vector<ll>d;
	fore(i,0,SZ(v)-1){
		fore(j,i+1,SZ(v)){
			d.pb(v[j]-v[i]);
		}	
	}
	ll res=0;
	fore(i,0,SZ(d)){
		res=gcd(res,d[i]);
	}
	cout<<"! "<<l-(n-1)*res<<" "<<res<<endl;
	return 0;
}