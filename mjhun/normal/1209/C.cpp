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
char s[200005];

bool doit(int d){
	int p=-1;
	int h=0;
	fore(i,0,n){
		if(s[i]<d)continue;
		if(s[i]==d){
			if(p<0)h=i+1;
		}
		else {
			if(p>s[i])return false;
			p=s[i];
		}
	}
	int z=n;
	p=15;
	for(int i=n-1;i>=0;--i){
		if(s[i]>d)continue;
		if(s[i]==d){
			if(p>10)z=i;
		}
		else {
			if(p<s[i])return false;
			p=s[i];
		}
	}
	//printf(" %d\n",d);
	fore(i,0,n)if(s[i]==d&&i>=h&&i<z)return false;
	fore(i,0,n){
		if(s[i]<d||(s[i]==d&&i>=z))putchar('1');
		else putchar('2');
	}
	puts("");
	return true;
}

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		scanf("%d%s",&n,s);
		fore(i,0,n)s[i]-='0';
		bool r=0;
		fore(d,0,10)r=r||doit(d);
		if(!r)puts("-");
	}
	return 0;
}