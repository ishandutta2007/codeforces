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

char c[1010][1010];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			fore(j,0,n){
				cin>>c[i][j];
			}
		}
		if(m&1){
			cout<<"YES\n";
			fore(i,0,(m+1)/2)cout<<"1 2 ";
			cout<<"\n";
		}else{
			pair<ll,ll> pos={-1,-1};
			fore(i,0,n){
				fore(j,i+1,n){
					if(c[i][j]==c[j][i]){
						pos={i,j};
					}
				}
			}
			if(pos.fst!=-1){
				cout<<"YES\n";
				fore(i,0,(m+1)/2)cout<<pos.fst+1<<" "<<pos.snd+1<<" ";
				cout<<pos.fst+1<<"\n";
			}else{
				ll pos=-1;
				fore(i,0,n){
					ll ca=0,cb=0;
					fore(j,0,n){
						if(c[i][j]=='a')ca++;
						if(c[i][j]=='b')cb++;
					}
					if(ca&&cb){
						pos=i;
						break;
					}
				}
				if(pos!=-1){
					ll a=-1,b=-1;
					fore(j,0,n){
						if(c[pos][j]=='a')a=j;
						if(c[pos][j]=='b')b=j;
					}
					cout<<"YES\n";
					if(m%4==2){
						fore(i,0,m/4)cout<<a+1<<" "<<pos+1<<" ";
						cout<<a+1<<" "<<pos+1<<" "<<b+1<<" ";
						fore(i,0,m/4)cout<<pos+1<<" "<<b+1<<" ";
						cout<<"\n";
					}else{
						fore(i,0,m/4)cout<<pos+1<<" "<<a+1<<" "<<pos+1<<" "<<b+1<<" ";
						cout<<pos+1<<"\n";
					}
				}else{
					cout<<"NO\n";
				}
			}
		}
	}
	
	return 0;
}