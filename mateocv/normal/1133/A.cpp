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
	string s1,s2; cin>>s1>>s2;
	ll a[5],b[5];
	fore(i,0,5){
		if(i!=2){
			a[i]=s1[i]-'0';
			b[i]=s2[i]-'0';
		}
	}
	ll staart=(10*a[0]+a[1])*60+(10*a[3]+a[4]),endd=(10*b[0]+b[1])*60+(10*b[3]+b[4]);
	ll res=(staart+endd)/2;
	if(res<600)cout<<0;
	cout<<res/60<<":";
	if(res%60<10)cout<<0;
	cout<<res%60;
	return 0;
}