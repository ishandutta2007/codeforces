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
char s[10000][16];
set<string> z;
map<string,int> q;
map<string,int> w;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		scanf("%s",s[i]);
		int m=strlen(s[i]);
		z.clear();
		fore(a,0,m)fore(b,a+1,m+1)z.insert(string(s[i]+a,s[i]+b));
		for(string s:z)q[s]++,w[s]=i;
	}
	int qq;
	scanf("%d",&qq);
	while(qq--){
		char _t[16];
		scanf("%s",_t);
		string t(_t);
		if(!q.count(t))puts("0 -");
		else printf("%d %s\n",q[t],s[w[t]]);
	}
	return 0;
}