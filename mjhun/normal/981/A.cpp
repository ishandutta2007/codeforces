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

string s;

int main(){
	cin>>s;int n=SZ(s);
	int r=0;
	fore(i,0,n)fore(j,1,n-i+1){
		string t=s.substr(i,j);
		string tt=t;
		reverse(t.begin(),t.end());
		if(t!=tt)r=max(r,j);
	}
	printf("%d\n",r);
	return 0;
}