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

int mcd(int x){
	for(int i=90;i>0;i--){if((180%i==0)&&(x%i==0)){return i;
	}
	}
}

int main(){
	
	int t; cin>>t;
	while(t--){
		int ang; cin>>ang;
		int m=mcd(ang);
		if(ang/m<=(180/m-2)){cout<<180/m;
		}else{cout<<360/m;
		}
		cout<<endl;
	}
	
	
	return 0;
}