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
	ll h,n; cin>>h>>n;
	ll d[n],sum=0,mini=0;
	fore(i,0,n){
		cin>>d[i];
		sum+=d[i];
		mini=min(mini,sum);
	}
	if(sum>=0){
		if(abs(mini)<h){
			cout<<-1;
		}else{
			fore(i,0,n){
				h+=d[i];
				if(h<=0)cout<<i+1; break;
			}	
		}
	}else{
	    if(abs(mini)>=h){
	        fore(i,0,n){
				h+=d[i];
				if(h<=0){cout<<i+1; break;}
			}
	    }else{
	    
		h+=mini;
		ll res=(h+abs(sum)-1)/abs(sum);
		h-=mini;
		h+=res*sum;
	//	cout<<h<<"\n";
		fore(i,0,n){
			h+=d[i];
	//		cout<<h<<" ";
			if(h<=0){
				cout<<res*n+i+1; break;	
			}
		}
	}
	}
	
	return 0;
}