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
	ll q; cin>>q;
	while(q--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll res[n];
		mset(res,0);
		ll tot=0;
		fore(i,0,n){
			tot+=(a[i]==a[0]);
		}
		if(tot==n){
			cout<<1<<"\n";
			fore(i,0,n)cout<<"1 "; cout<<"\n";
			continue;
		}
		if(n%2==0){
			cout<<2<<"\n";
			fore(i,0,n)cout<<1+(i%2)<<" "; cout<<"\n";
			continue;
		}
		ll br=0;
		fore(i,0,n){
			if(a[i]==a[(i-1+n)%n]){
				res[(i-1+n)%n]=1;
				fore(j,0,n-1){
					res[(i+j)%n]=1+j%2;
				}
				cout<<2<<"\n";
				fore(i,0,n)cout<<res[i]<<" "; cout<<"\n";
				br++;
				break;
			}
		}
		if(br)continue;
		cout<<3<<"\n";
		fore(i,0,n){
			if(i==n-1)cout<<3<<" ";
			else cout<<1+(i%2)<<" ";	
		} 
		cout<<"\n";
		
	}
	
	return 0;
}