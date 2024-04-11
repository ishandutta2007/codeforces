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

int main(){FIN;
	ll n; cin>>n;
	ll X=0,Y=0,lle[2];
	fore(i,0,2*n){
		cin>>lle[0]>>lle[1];
		X+=lle[0]; Y+=lle[1];
	}
	cout<<X/n<<" "<<Y/n;
	
	return 0;
}