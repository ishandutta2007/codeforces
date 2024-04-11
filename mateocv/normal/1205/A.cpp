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
	ll n; cin>>n;
	if(n%2==0){
		cout<<"NO"; return 0;
	}
	cout<<"YES\n";
	fore(i,1,n+1){
		if(i%2==1){
			cout<<2*i-1<<" ";
		}else{
			cout<<2*i<<" ";
		}
	}
	fore(i,1,n+1){
		if(i%2==1){
			cout<<2*i<<" ";
		}else{
			cout<<2*i-1<<" ";
		}
	}
	
	return 0;
}