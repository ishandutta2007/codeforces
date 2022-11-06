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
	pair<ll,ll> a[n];
	fore(i,0,n)cin>>a[i].fst,a[i].snd=i;
	sort(a,a+n);
	reverse(a,a+n);
	ll res=0;
	fore(i,0,n)res+=1+i*a[i].fst;
	cout<<res<<"\n";
	fore(i,0,n)cout<<a[i].snd+1<<" ";
	
	return 0;
}