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


int nq;
//int rr;
bool ask(int x, int y){
	nq++;
	assert(nq<=60);
	//return x%rr>=y%rr;
	printf("? %d %d\n",x,y);fflush(stdout);
	char s[4];
	scanf("%s",s);
	return s[0]=='x';
}

char ss[16];

int main(){
	while(scanf("%s",ss),ss[0]=='s'){
		nq=0;
		int r;
		if(ask(1,2)){
			if(ask(2,1))r=1;
			else r=2;
		}
		else {
			int a=2;
			while(!ask(a,2*a))a*=2;
			int b=2*a; // r in (a,b]
			a++;b++;   // r in [a,b)
			while(b-a>1){
				int m=(a+b)/2;
				if(!ask(a-1,m-1))a=m;
				else b=m;
			}
			r=a;
		}
		printf("! %d\n",r);fflush(stdout);
	}
	return 0;
}