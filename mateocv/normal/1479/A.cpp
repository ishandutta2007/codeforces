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

const int MAXN=100005;

ll a[MAXN];

void check(ll pos){
	if(a[pos-1]!=-1&&a[pos+1]!=-1&&a[pos]!=-1&&min(a[pos-1],a[pos+1])>a[pos]){
		cout<<"! "<<pos<<endl;
		exit(0);
	}
}

ll n; 

ll ask(ll pos){
	cout<<"? "<<pos<<endl;
	ll resp; cin>>resp;
	a[pos]=resp;
	check(pos);
	if(pos-1>=1)check(pos-1);
	if(pos+1<=n)check(pos+1);
	return resp;
}

int main(){FIN;
	cin>>n;
	mset(a,-1);
	a[0]=9e18,a[n+1]=9e18;
	ask(1);
	ask(2);
	ask(n-1);
	ask(n);
	ll l=1,r=n-1;
	while(l<=r){
		ll m=(l+r)/2;
		ask(m);
		ask(m+1);
		if(a[m]<a[m+1])r=m-1;
		else l=m+1;
	}
	
	return 0;
}