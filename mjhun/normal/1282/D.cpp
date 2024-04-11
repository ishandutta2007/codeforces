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

int ask(string s){
	cout<<s<<endl;cout.flush();
	int r;
	cin>>r;
	if(r==0)exit(0);
	return r;
}

string bs,r;

int main(){
	int n=ask("a")+1,q=0;
	if(n>300){
		ask(string(n-1,'b'));
		assert(0);
	}
	if(n==2){
		int b=ask("b");
		if(b==2){
			ask("aa");
			assert(0);
		}
		ask("ab");
		ask("ba");
		assert(0);
	}
	bs=r=string(n,'b');
	int t=ask(bs);
	fore(i,0,n-1){
		string s=bs;
		s[i]='a';
		int t2=ask(s);
		if(i==0&&t==1&&t2==1){
			ask(string(n-1,'b'));
			assert(0);
		}
		if(t2<t)r[i]='a',q++;
	}
	if(q<t)r[n-1]='a';
	ask(r);
	assert(0);
	return 0;
}