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

ll a[200005];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			cin>>a[i]; a[i]--;
		}
		ll disp=0,dispn=0,res=0,ul=-1;
		fore(i,1,n){
			if(ul==-1||ul<a[i]){
				dispn++;
				ul=a[i];
			}else{
				if(disp){
					disp--;
					ul=a[i];
				}else{
					disp=dispn;
					dispn=0;
					disp--;
					res++;
					ul=a[i];
				}
				dispn++;
			}
		}
		cout<<res+1<<"\n";
	}
	
	return 0;
}