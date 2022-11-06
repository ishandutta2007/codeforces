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

int main(){FIN;
	ll l,h; cin>>h>>l;
	double t=atan(1.*l/h);
	double d=hypot(l,h);
	d/=2;
	double p=d/cos(t);
	cout<<fixed<<setprecision(12)<<p-h;
	return 0;
}