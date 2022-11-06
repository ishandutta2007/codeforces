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

ll dist(char a, char F){
	ll res=0;
	fore(i,0,26){
	    //cout<<char('A'+(i+a)%26)<<"\n";
		if(F==char('A'+(i+a-'A')%26)){
			res=i; break;
		}
	}
	if(res>13)return 26-res;
	return res;
}

ll solve(char a,char b,char c,char d){
	ll res=0;
	res+=dist(a,'A'); //cout<<dist(a,'A')<<" ";
	res+=dist(b,'C'); //cout<<dist(b,'C')<<" ";
	res+=dist(c,'T'); //cout<<dist(c,'T')<<" ";
	res+=dist(d,'G'); //cout<<dist(d,'G')<<" ";
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	ll res=1ll*1e12;
	fore(i,0,n-3){
		res=min(res,solve(s[i],s[i+1],s[i+2],s[i+3]));
	}
	cout<<res;
	return 0;
}