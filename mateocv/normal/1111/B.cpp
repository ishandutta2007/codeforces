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
	ll n,m,k; cin>>n>>k>>m;
	vector<ll> v;
	ll llega;
	fore(i,0,n){
		cin>>llega;
		v.pb(llega);	
	}
	sort(v.rbegin(),v.rend());
	/*while(1){
		if(v[0]>v.back()&&m>0&&n>1){
			v.pop_back(); m--; n--;
		}else{break;
		}
	}*/
	ll suma=0;
	for(auto it:v){
		suma+=it;
	}
	
	/*if(m==0){
		cout<<fixed<<setprecision(13)<<1.*suma/n;
	}else{*/
		double maxi=0; //ll maxid=-1;
		fore(i,0,min(n,m+1)){
			if(i>0){suma-=v.back(); v.pop_back();
			}
			maxi=max(maxi,1.*suma/(n-i)+1.*min((n-i)*k,m-i)/(n-i));
		//	cout<<fixed<<setprecision(13)<<maxi;
			/*if(maxi==){
				maxid=i;
			}*/
		}
		cout<<fixed<<setprecision(13)<<maxi;
	//}
	
	return 0;
}