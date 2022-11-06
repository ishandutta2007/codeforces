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
	string s; cin>>s;
	ll res=0;
	fore(i,0,SZ(s)){
		if((s[i]=='0')||(s[i]=='2')||(s[i]=='4')||(s[i]=='6')||(s[i]=='8')){
			res+=i+1;		
		}
	}
cout<<res;
	
	return 0;
}