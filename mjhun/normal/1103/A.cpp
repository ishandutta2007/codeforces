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

char s[1024];

int main(){
	scanf("%s",s);
	bool a=false,b=false;
	for(int i=0;s[i];++i){
		if(s[i]=='0'){
			if(!a)puts("1 1");
			else puts("3 1");
			a=!a;
		}
		else {
			if(!b)puts("4 3");
			else puts("4 1");
			b=!b;
		}
	}
	return 0;
}