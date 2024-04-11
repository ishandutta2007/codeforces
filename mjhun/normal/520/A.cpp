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
#define mset(x,a) (memset((x),(a),sizeof(x)))
#define mcpy(x,y) (memcpy((x),(y),sizeof(x)))
using namespace std;
typedef long long ll;

int n;
char s[128];
bool w[32];

int main(){
	scanf("%d%s",&n,s);
	fore(i,0,n){
		char c=s[i];
		if(c>='a'&&c<='z')w[c-'a']=true;
		else w[c-'A']=true;
	}
	bool r=true;
	fore(i,0,26)if(!w[i])r=false;
	puts(r?"YES":"NO");
	return 0;
}