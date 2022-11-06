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
	ll n,m; cin>>n>>m;
	ll a[n];//sum=0;
	fore(i,0,n){
		cin>>a[i];
		//sum+=a[i];
	}
	sort(a,a+n);
	ll sump[n];
	memset(sump,0,sizeof sump);
	
	fore(i,0,n){
		if(i==0){
			sump[i]=a[n-1];
		}else{
			sump[i]=sump[i-1]+a[n-i-1];
		}
	}
	if(sump[n-1]<m){cout<<-1;
	}else{
		ll l=1,r=n;
		while(l <= r) {
		 ll mid = (l+r)/2;
		 ll /*res=0,*/ok=0;
		 fore(j,1,n+1){
				ll di=j/mid;
				if((sump[j-1]-(di*mid*(di-1))/2-(j%mid)*di)>=m){/*res=mid;*/ ok++; break;
				}
				
			}
			if(ok){r=mid-1;
			}else{l=mid+1;
			}
		}
		
		cout<<r+1;
		
			
		/*	fore(j,1,n+1){
				ll di=j/i;
				if((sump[j-1]-(di*i*(di-1))/2-(j%i)*di)>=m){cout<<i;
			}
			}*/
			
		
	}
	return 0;
}