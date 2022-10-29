#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...)
#define deb1(x)
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

vector<int> kmppre(string t){
	vector<int> r(t.size()+1);r[0]=-1;
	int j=-1;
	fore(i,0,t.size()){
		while(j>=0&&t[i]!=t[j])j=r[j];
		r[i+1]=++j;
	}
	return r;
}
bool kmp(string s, string t){
	int j=0;vector<int> b=kmppre(t);
	fore(i,0,s.size()){
		while(j>=0&&s[i]!=t[j])j=b[j];
		if(++j==t.size())return true;
	}
	return false;
}

int f(string s0, string s1){
	vector<int> b=kmppre(s1+s0);
	int r=b.back();
	while(r>s0.size()&&r>s1.size())r=b[r];
	return r;
}

string join(string s0, string s1){
	if(kmp(s0,s1))return s0;
	if(kmp(s1,s0))return s1;
	int k=f(s0,s1);
	string r=s0;
	fore(i,k,s1.size())r.pb(s1[i]);
	return r;
}

int doit(string s0, string s1, string s2){
	if(kmp(s0,s1)||kmp(s2,s1))return join(s0,s2).size();
	return join(join(s0,s1),s2).size();
}

char _s0[100005],_s1[100005],_s2[100005];
string s[3];

int main(){
	while(scanf("%s%s%s",_s0,_s1,_s2)!=EOF){
		s[0]=string(_s0);s[1]=string(_s1);s[2]=string(_s2);
		int r=1<<30;
		vector<int> v={0,1,2};
		do {
			r=min(r,doit(s[v[0]],s[v[1]],s[v[2]]));
		} while(next_permutation(v.begin(),v.end()));
		printf("%d\n",r);
	}
	return 0;
}