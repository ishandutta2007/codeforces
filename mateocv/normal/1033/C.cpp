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

string res;

ll a[100005];
ll u[100005];
ll n;

void solve(ll m){
	if(m==n){
		res[u[m]]='B'; return;
	}
	for(ll i=u[m]+m;i<n;i+=m){
		if(a[i]>m&&res[i]=='B'){
			res[u[m]]='A'; return;
		}
	}
	for(ll i=u[m]-m;i>=0;i-=m){
		if(a[i]>m&&res[i]=='B'){
			res[u[m]]='A'; return;
		}
	}
	res[u[m]]='B';
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)res.pb('.');
	fore(i,0,n)u[a[i]]=i;
	fore(i,0,n)solve(n-i);
	cout<<res;
	return 0;
}