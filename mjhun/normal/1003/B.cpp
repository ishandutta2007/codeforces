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

int a,b,x;bool s;
char r[256];

int main(){
	scanf("%d%d%d",&a,&b,&x);
	int n=a+b;
	s=a>b;
	if(s)swap(a,b);
	fore(i,0,n)r[i]='1';
	if(x==2*a){
		fore(i,0,a)r[2*i+1]='0';
	}
	else {
		r[n-1]='0';x--;a--;
		if(x%2){
			x++;
			for(int i=0;x;i+=2)x-=2,a--,r[i]='0';
		}
		else {
			for(int i=1;x;i+=2)x-=2,a--,r[i]='0';
		}
		int k=n-2;
		assert(a>=0);
		while(a)a--,r[k--]='0';
	}
	if(s)fore(i,0,n)r[i]='0'+1-(r[i]-'0');
	puts(r);
	return 0;
}