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

int n;
map<string,vector<string> > w;

bool comp(string s1, string s2){
	return SZ(s1)>SZ(s2);
}

int main(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	while(n--){
		string s;int k;
		cin>>s>>k;
		while(k--){
			string t;
			cin>>t;
			w[s].pb(t);
		}
	}
	cout<<SZ(w)<<'\n';
	for(auto p:w){
		cout<<p.fst;
		vector<string> z;
		auto v=p.snd;
		sort(v.begin(),v.end(),comp);
		for(auto s:v){
			bool can=true;
			for(auto t:z)if(equal(s.rbegin(),s.rend(),t.rbegin())){
				can=false;
				break;
			}
			if(can)z.pb(s);
		}
		cout<<' '<<SZ(z);
		for(auto s:z)cout<<' '<<s;
		cout<<'\n';
	}
	return 0;
}