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

ll n; 

int main(){FIN;
	cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	if(n==1){
		cout<<"1 1\n"<<-a[0]<<"\n";
		fore(k,0,2)cout<<"1 1\n0\n";
		return 0;
	}
	ll r[n];
	fore(i,0,n){
		r[(n-1)*i%n]=(n-1)*i;
	}
	//for(auto i:v)cout<<i<<" "; cout<<"\n";
	//fore(i,0,n)cout<<r[i]<<" "; cout<<"\n";
	cout<<"1 "<<n-1<<"\n";
	fore(i,0,n-1)cout<<-r[(a[i]%n+n)%n]<<" ",a[i]-=r[(a[i]%n+n)%n]; cout<<"\n";
	cout<<n<<" "<<n<<"\n"<<-a[n-1]<<"\n";
	a[n-1]=0;
	cout<<"1 "<<n<<"\n";
	fore(i,0,n)cout<<-a[i]<<" ";
	
	
	return 0;
}