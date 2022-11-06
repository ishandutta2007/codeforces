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
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll x,y,z,a,b,c; cin>>x>>y>>z>>a>>b>>c;
	if((x<=a)&&(y<=a+b-x)&&(z<=a+b+c-x-y)){
		cout<<"YES";
	}else{cout<<"NO";
	}
	
//	cout<<" "<<(x>=a)<<" "<<(y>=a+b-x)<<" "<<(z>=a+b+c-x-y);
	
	return 0;
}