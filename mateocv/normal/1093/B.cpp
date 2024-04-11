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
	int t; cin>>t;
	while(t--){
		string s; cin>>s;
		sort(s.begin(),s.end());
		if(s[0]==s[SZ(s)-1]){
			cout<<-1<<"\n";
		}else{
			cout<<s<<"\n";
		}
		
	}
	
	return 0;
}