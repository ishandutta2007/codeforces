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
	string s; cin>>s;
	vector<char> v;
	int van=0;
	fore(i,0,SZ(s)){v.pb(s[i]);
		if(v[SZ(v)-1]==v[SZ(v)-2]){van++;
			v.pop_back(); v.pop_back();
		}
	}
	
	if(van&1){cout<<"YES";
	}else{cout<<"NO";
	}
	
	return 0;
}