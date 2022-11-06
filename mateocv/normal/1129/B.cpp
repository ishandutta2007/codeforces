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
	ll k; cin>>k;
	cout<<2000<<"\n"<<-1<<" ";
	k+=2000;
	fore(i,0,1999){
		if(k>=1000000){
			cout<<1000000<<" "; k-=1000000;
		}else{
			cout<<k<<" "; k=0;
		}
	}
	
	return 0;
}