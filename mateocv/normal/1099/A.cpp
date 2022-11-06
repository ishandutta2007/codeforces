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
	
	int w,h; cin>>w>>h;
	int w1,h1,w2,h2;cin>>w1>>h1>>w2>>h2;
	for(int i=h;i>0;i--){
		w+=i;
		if(i==h1){if(w>w1){w-=w1;
		}else w=0;
		};
		if(i==h2){if(w>w2){w-=w2;
		}else w=0;
		};
	};
	
	cout<<w;
	
	return 0;
}