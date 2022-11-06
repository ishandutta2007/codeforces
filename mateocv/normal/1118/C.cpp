#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	ll a[1005];
	ll llega;
	vector<pair<ll,ll>> v;
	memset(a,0,sizeof a);
	fore(i,0,n*n){
		cin>>llega;
		a[llega]++;
	}
	fore(i,0,1005){
		pair<ll,ll> p;
		if(a[i]>0){
			p.fst=a[i];
			p.snd=i;
			v.pb(p);
		}
	}
	sort(v.begin(),v.end());
	ll res[n][n];
	ll okk=0;
	if(n%2==0){
		fore(i,0,n/2){
			fore(j,0,n/2){
				ll elk=-1,el,ok=0;
				fore(k,0,SZ(v)){
					if(v[k].fst>=4){elk=k;el=v[k].snd;ok++; break;
					}
				}
				if(!ok){okk++; break;
				}
				res[i][j]=el;
				res[n-1-i][j]=el;
				res[i][n-1-j]=el;
				res[n-1-i][n-1-j]=el;
				v[elk].fst-=4;
				
			}
			if(okk)break;
		}
	}else{
		fore(i,0,n/2){
			fore(j,0,n/2){
				ll elk=-1,el,ok=0;
				fore(k,0,SZ(v)){
					if(v[k].fst>=4){elk=k;el=v[k].snd;ok++; break;
					}
				}
				if(!ok){okk++; break;
				}
				res[i][j]=el;
				res[n-1-i][j]=el;
				res[i][n-1-j]=el;
				res[n-1-i][n-1-j]=el;
				v[elk].fst-=4;
				
			}
			if(okk)break;
		}
		
		fore(i,0,n/2){
			ll elk=-1,el,ok=0;
				fore(k,0,SZ(v)){
					if(v[k].fst>=2){elk=k;el=v[k].snd;ok++; break;
					}
				}
				if(!ok){okk++; break;
				}
				res[i][n/2]=el;
				res[n-1-i][n/2]=el;
				v[elk].fst-=2;
		}
		fore(i,0,n/2){
			ll elk=-1,el,ok=0;
				fore(k,0,SZ(v)){
					if(v[k].fst>=2){elk=k;el=v[k].snd;ok++; break;
					}
				}
				if(!ok){okk++; break;
				}
				res[n/2][i]=el;
				res[n/2][n-1-i]=el;
				v[elk].fst-=2;
		}
		ll elk=-1,el=0,ok=0;
				fore(k,0,SZ(v)){
					if(v[k].fst>=1){elk=k;el=v[k].snd;ok++; break;
					}
				}
				if(!ok){okk++;
				}
				res[n/2][n/2]=el;
				v[elk].fst-=1;
		
	}
	if(okk){cout<<"NO";
	}else{
		cout<<"YES\n";
		fore(i,0,n){
			fore(j,0,n){
				cout<<res[i][j]<<" ";
			}
			cout<<"\n";	
		}
	}
	
	return 0;
}