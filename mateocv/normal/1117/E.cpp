#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mpair make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	string s; cin>>s;
	string q[3];
	map<string,ll> mp;
	fore(i,0,SZ(s)){
		string form="";
		q[0]+=('a'+i/385);
		q[1]+=('a'+(i/15)%26);
		q[2]+=('a'+i%26);
		form+=('a'+i/385);
		form+=('a'+(i/15)%26);
		form+=('a'+i%26);
		mp[form]=i;
	}
	//cout<<q[0]<<" "<<q[1]<<" "<<q[2];
	string r[3];
	fore(i,0,3){
		cout<<"? "<<q[i]<<endl;
		cin>>r[i];
	}
	ll pos[SZ(s)];
	fore(i,0,SZ(s)){
		string form="";
		form+=r[0][i];
		form+=r[1][i];
		form+=r[2][i];
		pos[mp[form]]=i;
	}
	cout<<"! ";
	fore(i,0,SZ(s)){
		cout<<s[pos[i]];		
	}
	return 0;
}