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
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int n;
map<pair<string,string>,vector<int> > w;

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	fore(i,0,n){
		string s,t;
		cin>>s>>t;
		sort(t.begin(),t.end());
		t.erase(unique(t.begin(),t.end()),t.end());
		while(!s.empty()&&binary_search(t.begin(),t.end(),s.back()))s.pop_back();
		w[mp(s,t)].pb(i);
	}
	printf("%d\n",SZ(w));
	for(auto p:w){
		auto v=p.snd;
		printf("%d",SZ(v));
		for(int t:v)printf(" %d",t+1);
		puts("");
	}
	return 0;
}