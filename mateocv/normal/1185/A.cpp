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
	ll a[3];
	fore(i,0,3)cin>>a[i];
	ll d; cin>>d;
	sort(a,a+3);
	cout<<max(0ll,d-(a[1]-a[0]))+max(0ll,d-(a[2]-a[1]));
	
	return 0;
}