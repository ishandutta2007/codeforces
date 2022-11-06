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
	
	int n; cin>>n;
	int s=sqrt(n);
	if(s*s>=n){cout<<2*s;
	}else if(s*(s+1)>=n){cout<<2*s+1;
	}else {cout<<2*s+2;
	}
	
	return 0;
}