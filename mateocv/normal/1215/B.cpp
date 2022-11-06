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
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll pos=0,neg=0;
	ll vap=0,van=0;
	fore(i,0,n){
		if(a[i]>0){
			vap++;
		}else{
			swap(vap,van); van++;
		}
		pos+=vap; neg+=van;
		//cout<<neg<<" "<<pos<<"\n";
	}
	cout<<neg<<" "<<pos<<"\n";
	return 0;
}