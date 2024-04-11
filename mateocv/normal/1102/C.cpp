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
	
	int n,x,y; cin>>n>>x>>y;
	int a[n],chicas=0;
	fore(i,0,n){cin>>a[i];if(a[i]<=x){
	chicas++;}
	}
	if(x>y){cout<<n;
	}else{cout<<(chicas+1)/2;
	}
	
	return 0;
}