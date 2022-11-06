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

ll spow(ll b, ll e){
	ll r=1;
	fore(i,0,e)r*=b;
	return r;
}

int main(){FIN;
	ll n; cin>>n;
	string s="codeforces";
	fore(i,1,41){
		if(spow(i,10)>=n){
			ll res[10];
			fore(j,0,10)res[j]=i-1;
			fore(j,0,10){
				ll prod=1;
				fore(jj,0,10)prod*=res[jj];
				if(prod>=n){
					fore(jj,0,10){
						fore(_,0,res[jj])cout<<s[jj];
					}
					return 0;
				}
				res[j]++;
			}
		}
	}
	
	return 0;
}