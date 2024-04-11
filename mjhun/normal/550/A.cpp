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

char s[100005];int n;

int main(){
	scanf("%s",s);n=strlen(s);
	bool w=false;
	fore(i,0,n){
		if(s[i]=='B'&&s[i+1]=='A'&&w){puts("YES");return 0;}
		else if(!w&&s[i]=='A'&&s[i+1]=='B'){w=true;i++;}
	}
	w=false;
	fore(i,0,n){
		if(s[i]=='A'&&s[i+1]=='B'&&w){puts("YES");return 0;}
		else if(!w&&s[i]=='B'&&s[i+1]=='A'){w=true;i++;}
	}
	puts("NO");
	return 0;
}