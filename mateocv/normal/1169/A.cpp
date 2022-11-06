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
	ll n,a,x,b,y; cin>>n>>a>>x>>b>>y; a--; b--; x--; y--;
	while(a!=x&&b!=y){
		a++; a=(a+n)%n;
		b--; b=(b+n)%n;
		if(a==b){
			cout<<"YES"; return 0;
		}
	}
	
	cout<<"NO";
	return 0;
}