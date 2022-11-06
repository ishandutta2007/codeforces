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
	ll n,m; cin>>n>>m;
	ll res=0;
	if(m%n==0){
		ll d=m/n;
		while(d>1){
			if(d%2==0){res++; d/=2;
			}else if(d%3==0){
				res++; d/=3;
			}else{
				break;
			}
		}
		if(d==1){
			cout<<res;
		}else{
			cout<<-1;
		}
	}else{
		cout<<-1;
	}
	
	
	return 0;
}