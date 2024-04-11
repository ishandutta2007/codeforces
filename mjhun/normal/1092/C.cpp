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
vector<pair<string,int> > s[128];
char r[256];
string t;

bool pref(string s){
	fore(i,0,SZ(s))if(s[i]!=t[i])return false;
	return true;
}

bool suf(string s){
	fore(i,0,SZ(s))if(s[i]!=t[SZ(t)-SZ(s)+i])return false;
	return true;
}

void doit(){
	fore(i,1,n){
		if(pref(s[i][0].fst)&&suf(s[i][1].fst))r[s[i][0].snd]='P',r[s[i][1].snd]='S';
		else if(pref(s[i][1].fst)&&suf(s[i][0].fst))r[s[i][1].snd]='P',r[s[i][0].snd]='S';
		else return;
	}
	puts(r);
	exit(0);
}

int main(){
	cin>>n;
	fore(_,0,2*n-2){
		cin>>t;
		s[SZ(t)].pb(mp(t,_));
	}
	fore(i,0,26){
		t=s[n-1][0].fst;
		t.pb('a'+i);
		doit();
		t=s[n-1][1].fst;
		t.pb('a'+i);
		doit();
	}
	assert(0);
	return 0;
}