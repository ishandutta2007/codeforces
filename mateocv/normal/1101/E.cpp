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
	char c; int a,b;
	int maxx=0,maxy=0;
	while(n--){
		cin>>c>>a>>b;
		int mx=max(a,b),mn=a+b-mx;
		if(c=='+'){
		/*if(mx>maxx){maxx=mx;
		}
		if(mn>maxy){maxy=mn;
		}*/
		maxx=max(maxx,mx);
		maxy=max(maxy,mn);
		}
		if(c=='?'){if((mx>=maxx)&&(mn>=maxy)){cout<<"YES"<<"\n";
		}else{cout<<"NO"<<"\n";
		}
	//	cout<<max(a,b)<<" "<<min(a,b)<<" "<<maxy<<endl;
		}
	}
	
	
	return 0;
}