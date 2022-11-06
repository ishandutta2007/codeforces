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

ll MOD=998244353;

ll prim(string &st){
	fore(i,1,SZ(st)){
		if(st[i]!=st[0]){return i;
		}
	}
	return 0;
}

int main(){

	ll n; cin>>n;
	string s; cin>>s;
	string s1=s;
	fore(i,0,n){s1[i]=s[n-1-i];
	}
	
	if(s[0]==s[n-1]){if(prim(s)==0){cout<<(n*(n+1)/2)%MOD;
	}else{if((prim(s)+prim(s1))==n){cout<<((prim(s)+1)*(prim(s1)+1)-1)%MOD;
	}else{cout<<((prim(s)+1)*(prim(s1)+1))%MOD;
	}
	}
	}else{cout<<prim(s)+prim(s1)+1;
	}
//	cout<<s1;
	
	
	return 0;
}