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
	ll k; cin>>k;
	string s,t; cin>>s>>t;
	ll c[k+1];
	mset(c,0);
	ll r=0;
	fore(i,0,k){
		c[i]=0+s[k-1-i]-'a'+t[k-1-i]-'a'+r;
	/*	if(c[i]>25){
			r=c[i]-25;
		}*/
		r=c[i]-c[i]%26;
		r/=26;
		c[i]%=26;
	}
	c[k]=r;
	/*fore(i,0,k+1){
		cout<<(c[k-i]);
	}
	cout<<"\n";*/
	for(ll i=k;i>=1;i--){
		if(c[i]%2){
			r=1;
			c[i]--;
		}
		c[i]/=2;
		c[i-1]+=26*r;
		r=0;
	}
	c[0]/=2;
	fore(i,0,k){
		cout<<char('a'+c[k-1-i]);
	}
	
	return 0;
}