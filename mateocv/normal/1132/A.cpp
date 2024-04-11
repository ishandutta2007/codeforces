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
	ll a,b,c,d; cin>>a>>b>>c>>d;
	if(a==d){
		if(a==0){
			if(c==0){
				cout<<1;	
			}else{
				cout<<0;
			}
		}else{
			cout<<1;
		}
	}else{
		cout<<0;
	}
	
	return 0;
}