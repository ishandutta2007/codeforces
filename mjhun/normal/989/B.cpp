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

int n,p;
char s[2048];
char t[256];

int main(){
	t['0']='1';
	t['1']=t['.']='0';
	bool c=false;
	scanf("%d%d%s",&n,&p,s);
	fore(i,0,n){
		if(s[i]=='.'){
			if(i>=p)s[i]=t[s[i-p]],c=true;
			else if(i+p<n)s[i]=t[s[i+p]],c=true;
			else s[i]='0';
		}
		else if(i+p<n&&s[i]!=s[i+p])c=true;
	}
	puts(c?s:"No");
	return 0;
}