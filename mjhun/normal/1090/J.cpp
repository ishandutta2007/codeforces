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

vector<int> z_function(string& s){
	int l=0,r=0,n=s.size();
	vector<int> z(s.size(),0);
	fore(i,1,n){
		if(i<=r)z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
	return z;
}

vector<int> kmppre(string& t){
	vector<int> r(t.size()+1);r[0]=-1;
	int j=-1;
	fore(i,0,t.size()){
		while(j>=0&&t[i]!=t[j])j=r[j];
		r[i+1]=++j;
	}
	return r;
}

string s,t,w;
int c[100005];

int main(){
	cin>>s>>t;
	w=t+'#'+s;
	auto z=z_function(w);
	fore(i,1,SZ(s))c[z[SZ(t)+1+i]]++;
	for(int i=100003;i>=0;--i)c[i]+=c[i+1];
	auto b=kmppre(t);
	ll r=1LL*SZ(s)*SZ(t);
	fore(i,2,SZ(t)+1)if(b[i])r-=c[i-b[i]];
	cout<<r<<endl;
	return 0;
}