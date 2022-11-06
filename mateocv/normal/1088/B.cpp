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
	ll n,k; cin>>n>>k;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	ll tot=0;
	fore(i,0,n){
		if(a[i]>tot){
			if(k){
				cout<<a[i]-tot<<"\n";
				tot+=a[i]-tot; k--;
				if(!k)break;
			}
			
		}
	}
	fore(i,0,k){
		cout<<"0\n";
	}
	
	return 0;
}