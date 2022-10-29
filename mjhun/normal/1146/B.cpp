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

void perdi(){puts(":(");exit(0);}

char s[100005];int n,q;
string ss,tt;

int main(){
	scanf("%s",s);n=strlen(s);
	fore(i,0,n)q+=s[i]!='a';
	if(q%2)perdi();
	q/=2;
	int i=0;
	while(SZ(ss)!=q){
		if(s[i]!='a')ss.pb(s[i]);
		i++;
	}
	while(i<n&&s[i]=='a')i++;
	tt=string(s+i,s+n);
	if(ss!=tt)perdi();
	s[i]=0;
	puts(s);
	return 0;
}