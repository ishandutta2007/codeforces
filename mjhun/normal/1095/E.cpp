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
char _s[1<<20];
int s[1<<20];
int pingo[128];
int p[1<<20]; // pref mas chico arrancando de i

int main(){
	pingo['(']=1;pingo[')']=-1;
	scanf("%d%s",&n,_s);
	fore(i,0,n)s[i]=pingo[_s[i]];
	int ss=0,mx=0;
	for(int i=n-1;i>=0;--i){
		ss+=s[i];
		mx=max(mx,ss);
		p[i]=ss-mx;
	}
	int z=0,r=0;
	fore(i,0,n){
		if(s[i]*2==ss){
			int zz=z-s[i];
			if(zz+p[i+1]>=0)r++;
		}
		z+=s[i];
		if(z<0)break;
	}
	printf("%d\n",r);
	return 0;
}