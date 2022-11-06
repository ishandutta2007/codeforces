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
	string a,b; cin>>a>>b;
	if(SZ(a)!=SZ(b)){cout<<"No";
	}else{
		ll cuenta=0;
		fore(i,0,SZ(a)){
			if(!(((a[i]=='a')||(a[i]=='e')||(a[i]=='i')||(a[i]=='o')||(a[i]=='u'))^((b[i]=='a')||(b[i]=='e')||(b[i]=='i')||(b[i]=='o')||(b[i]=='u')))){
				cuenta++;	
			}
		}
		if(cuenta==SZ(a)){cout<<"Yes";
		}else{cout<<"No";
		}
	}
	
	return 0;
}