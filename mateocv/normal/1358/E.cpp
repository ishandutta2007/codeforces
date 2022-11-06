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

int main(){FIN;
	ll n; cin>>n;
	ll a[(n+1)/2];
	fore(i,0,(n+1)/2){
		cin>>a[i];
	}
	ll x; cin>>x;
	if(x>0){
		ll s=0;
		fore(i,0,(n+1)/2)s+=a[i];
		s+=(n/2)*x;
		if(s>0){
			cout<<n;
		}else{
			cout<<-1;
		}
		return 0;
	}
	ll d[(n+1)/2+1];
	d[0]=0;
	fore(i,0,(n+1)/2){
		d[i+1]=d[i]+x-a[i];
	}
	//fore(i,0,(n+1)/2+1)cout<<d[i]<<" "; cout<<"\n";
	ll m[(n+1)/2+1];
	m[0]=0;
	fore(i,0,(n+1)/2){
		m[i+1]=min(m[i],d[i+1]);
	}
	//fore(i,0,(n+1)/2+1)cout<<m[i]<<" "; cout<<"\n";
	ll s=0;
	fore(i,0,(n+1)/2)s+=a[i];
	fore(i,0,n/2+1){
		if(s+m[n-((n+1)/2+i)]>0){
			cout<<(n+1)/2+i;
			return 0;
		}
		s+=x;
	}
	cout<<-1;
	return 0;
}