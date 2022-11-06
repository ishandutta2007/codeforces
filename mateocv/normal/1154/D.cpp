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
	ll n,b,a; cin>>n>>b>>a;
	ll s[n];
	fore(i,0,n)cin>>s[i];
	ll ba=b,ac=a;
	ll res=0;
	fore(i,0,n){
		if(s[i]==0){
			if(ac>0){
				res++;
				ac--;
			}else if(ba>0){
				res++;
				ba--;
			}else{
				break;
			}
		}else{
			if(ac==a){
				res++;
				ac--;
			}else if(ba>0){
				res++;
				ba--;
				ac=min(a,ac+1);
			}else if(ac>0){
				res++;
				ac--;
			}else{
				break;
			}
		}
	}
	cout<<res;
	
	return 0;
}