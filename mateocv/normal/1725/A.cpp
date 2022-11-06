#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){FIN;
	ll n,m; cin>>n>>m;
	
	if(min(n,m)==1) cout<<max(n,m)-1<<"\n";
	else cout<<n*(m-1)<<"\n";
}