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
	
	int q; cin>>q;
	
	while(q--){
		int l,r; cin>>l>>r;
		int res=0;
		if(l%2==0){res+=l;l++;
		}
		if(r%2){res-=r;r--;
		}
		res+=(r-l+1)/2;
		cout<<res<<endl;
	}
	return 0;
}