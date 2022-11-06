#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll ask(ll n){
	cout<<"? ";
	fore(i,1,101)cout<<i*n<<" "; cout<<endl;
	ll resp; cin>>resp;
	assert(resp!=-1);
	return resp;
}

int main(){FIN;
	ll res=0;
	ll a=ask(1);
	ll b=ask(1<<7);
	fore(i,0,7)res^=((1<<i)&b);
	fore(i,7,14)res^=((1<<i)&a);
	cout<<"! "<<res;
	return 0;
}