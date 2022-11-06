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

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int n; cin>>n;
	int a=-1,b=-1,llega;
	fore(i,0,n){
	    if(i==0){cin>>a; a%=2;}else
	    if(i==1){cin>>b; b%=2;}else
	    {cin>>llega; llega%=2;
	        if(a!=b){cout<<(llega==a)+1; break;}else
	        if(a!=llega){cout<<i+1; break;}
	    }
	}
	
	return 0;
}