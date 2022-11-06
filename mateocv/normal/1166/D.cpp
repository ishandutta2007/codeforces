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
	ll q; cin>>q;
	while(q--){
		ll a,b,m; cin>>a>>b>>m;
		if(a==b){
			cout<<"1 "<<a<<"\n";
		}else{
			fore(i,0,49){
				if(b>(1LL<<i)*(a+m))continue;
				if(b<(1LL<<i)*(a+1)){cout<<-1<<"\n"; break;}
				b-=(1LL<<i)*(a+1);
				//cout<<b<<" ";
				ll r[i+1];
				for(ll j=i;j>=0;j--){
					r[j]=min(m-1,b/(1LL<<(max(0ll,j-1))));
					b-=(1LL<<(max(0ll,j-1)))*r[j];
					//cout<<b<<" ";
				}
				//cout<<"\n";
				fore(j,0,i+1)r[j]++;
				reverse(r,r+i+1);
				//fore(j,0,i+1)cout<<r[j]<<" "; cout<<"\n";
				ll va=0,p=a;
				cout<<i+2<<" "<<a<<" ";
				fore(j,0,i+1){
					cout<<va+p+r[j]<<" ";
					va+=p; va*=2; p=r[j];
				}
				cout<<"\n"; break;
			}	
		}
	}
	
	return 0;
}