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
	ll n; cin>>n;
	ll a=0,b=0,l;
	fore(i,0,n){
		cin>>l;
		if(l==1){
			a++;
		}else{
			b++;
		}
	}
	if(a==0){
		fore(i,0,n){
			cout<<2<<" ";
		}
		return 0;
	}
	if(b==0){
		fore(i,0,n){
			cout<<1<<" ";
		}
		return 0;
	}
	cout<<"2 1 ";
	a--; b--;
	fore(i,0,b){
		cout<<"2 ";
	}
	fore(i,0,a){
		cout<<"1 ";
	}
	
	return 0;
}