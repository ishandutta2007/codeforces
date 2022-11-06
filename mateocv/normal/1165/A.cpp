#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
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
	ll n,x,y; cin>>n>>x>>y;
	string s; cin>>s;
	ll res=0;
	reverse(ALL(s));
	fore(i,0,x){
		if(i!=y&&s[i]=='1')res++;
		if(i==y&&s[i]=='0')res++;
	}
	cout<<res;
	return 0;
}