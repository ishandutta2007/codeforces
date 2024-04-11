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

string l,t;
set<string> asd;
vector<string> z;
map<string,string> w;

int main(){
	ios::sync_with_stdio(false);
	while(getline(cin,l),l!="\\begin{thebibliography}{99}"){
		for(char c:l)t.pb(c);
	}
	fore(i,0,SZ(t))if(t[i]=='\\'){
		string s="";
		for(int j=i+6;t[j]!='}';++j)s.pb(t[j]);
		if(asd.count(s))continue;
		//cout<<"asd "<<s<<endl;
		z.pb(s);
	}
	bool ok=true;
	int k=0;
	while(getline(cin,l),l!="\\end{thebibliography}"){
		string s="";
		for(int j=9;l[j]!='}';++j)s.pb(l[j]);
		//cout<<"qwe "<<s<<endl;
		if(s!=z[k])ok=false;
		w[s]=l;
		k++;
	}
	if(ok){cout<<"Correct\n";return 0;}
	cout<<"Incorrect\n";
	cout<<"\\begin{thebibliography}{99}\n";
	fore(i,0,SZ(z))cout<<w[z[i]]<<'\n';
	cout<<"\\end{thebibliography}\n";
	return 0;
}