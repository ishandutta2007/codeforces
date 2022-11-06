#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

ll blancas(ll a, ll b, ll c, ll d){
	ll res=(c-a+1)*(d-b+1)/2;
	if(((a+b)%2==0)&&((c+d)%2==0)&&((c-a+1)%2)){res++;
	}
	return res;
}
ll negras(ll a, ll b, ll c, ll d){
	return (c-a+1)*(d-b+1)-blancas(a,b,c,d);
}
int main(){
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll a[4],b[4];
		fore(i,0,4){cin>>a[i]>>b[i];
		}
		ll totb=blancas(1,1,m,n);
	//	cout<<totb<<endl;
		totb+=negras(a[0],b[0],a[1],b[1]);
	//	cout<<totb<<endl;
		totb-=blancas(a[2],b[2],a[3],b[3]);
	//	cout<<totb<<endl;
		ll a0cor,b0cor,a1cor,b1cor;
		a0cor=max(a[0],a[2]);
		b0cor=max(b[0],b[2]);
		a1cor=min(a[1],a[3]);
		b1cor=min(b[1],b[3]);
	//	cout<<a0cor<<" "<<b0cor<<" "<<a1cor<<" "<<b1cor<<endl;
		if((a0cor<=a1cor)&&(b0cor<=b1cor)){
			totb-=negras(a0cor,b0cor,a1cor,b1cor);
		}
		cout<<totb<<" "<<m*n-totb<<endl;
		
	}
	
	return 0;
}