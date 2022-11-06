#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll esp(ll n){
	for(ll i=2;i*i<=n;i++){
		if(n%i==0)return 0;
	}
	return 1;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	if(n==2){
		cout<<"2 2\n1 2 2"; return 0;
	}
	fore(i,2*(n-2)+3,300000){
		if(esp(i)){
			cout<<"2 "<<i<<"\n";
			fore(j,3,n+1){
				cout<<"1 "<<j<<" 2\n";
			}
			cout<<"1 2 "<<i-2*(n-2)<<"\n";
			ll tot=0;
			fore(j,2,n+1){
				fore(jj,j+1,n+1){
					if(tot<m-n+1)cout<<j<<" "<<jj<<" "<<i+10<<"\n",tot++;
					else break;
				}
			}
			break;
		}
	}
	
	return 0;
}