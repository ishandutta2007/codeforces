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

char b[2048][2048];
int n,m;
int s[2048];

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n){
		scanf("%s",b[i]);
		fore(j,0,m)s[j]+=b[i][j]-'0';
	}
	fore(i,0,n){
		bool c=true;
		fore(j,0,m)if(s[j]==1&&b[i][j]=='1'){c=false;break;}
		if(c){puts("YES");return 0;}
	}
	puts("NO");
	return 0;
}