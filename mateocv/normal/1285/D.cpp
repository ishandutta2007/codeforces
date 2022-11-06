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
 
ll a[100005];
 
ll solve(ll l, ll r, ll b){
	if(b==-1)return 0;
	if(a[l]&(1<<b))return solve(l,r,b-1);
	if(!(a[r]&(1<<b)))return solve(l,r,b-1);
	ll el=l,er=r;
	while(el <= er) {
	  ll m = (el+er)/2;
	  if (a[m]&(1<<b)) er=m-1;
	  else el=m+1;
	}
	//cout<<l<<" "<<r<<" "<<b<<" -> "<<(1<<b)+min(solve(l,er,b-1),solve(el,r,b-1))<<"\n";
	return (1<<b)+min(solve(l,er,b-1),solve(el,r,b-1));
	
}
 
int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	cout<<solve(0,n-1,29);
	
	return 0;
}