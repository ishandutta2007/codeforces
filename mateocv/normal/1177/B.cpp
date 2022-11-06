#include <bits/stdc++.h>
#define pb push_back
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
	ll k; cin>>k;
	ll tot=0;
	ll p[13];
	p[0]=1;
	fore(i,1,13)p[i]=10*p[i-1];
	fore(i,1,13){
		if(k<=tot+9*p[i-1]*i){
			ll r=(k-tot-1)/i+p[i-1];
			//cout<<r<<" "<<i<<"\n";
			ll t=(k-tot-1)%i;
			while(t<0)t+=i;
			t=i-1-t;
			//cout<<t<<"\n";
			fore(j,0,t){
				r/=10;
			}
			cout<<r%10;
			break;
		}else{
			tot+=9*p[i-1]*i;
		}	
	}
	return 0;
}