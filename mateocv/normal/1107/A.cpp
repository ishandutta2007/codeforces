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
	int q; cin>>q;
	while(q--){
		int n; cin>>n;
		string s; cin>>s;
		if(n==2&&s[0]>=s[1]){cout<<"NO\n";
	}else{
		cout<<"YES\n2\n";
		cout<<s[0]<<" ";
		fore(i,1,n) cout<<s[i];
		cout<<"\n";
	}
}
	return 0;
}