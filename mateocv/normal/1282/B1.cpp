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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,p,k; cin>>n>>p>>k;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		sort(a,a+n);
		ll q=p;
		ll res=0,resp=0;
		fore(i,0,n){
			if(i%2==0){
				if(q>=a[i]){
					q-=a[i];
					resp++;
					if(i!=0)resp++;
				}else{
					break;
				}
			}
		}
		q=p;
		fore(i,0,n){
			if(i%2==1){
				if(q>=a[i]){
					q-=a[i];
					res+=2;
				}else{
					break;
				}
			}
		}
		cout<<max(resp,res)<<"\n";
	}
	
	return 0;
}