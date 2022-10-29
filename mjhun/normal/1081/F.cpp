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

int n,r[512],w[512];
int Q;
int t;

bool ask(int l, int r){ // [l,r)
	Q++;
	assert(Q<=10000);
	assert((n-l)%2!=r%2);
	printf("? %d %d\n",l+1,r);fflush(stdout);
	int nt;
	scanf("%d",&nt);
	if(((n-l)%2==0)==((nt-t)%2==0)){
		fore(i,l,n)w[i]^=1;
		t=nt;
		return true;
	}
	else {
		assert((r%2==0)==((nt-t)%2==0));
		fore(i,0,r)w[i]^=1;
		t=nt;
		return false;
	}
}


int main(){
	scanf("%d%d",&n,&t);
	if(n==1){
		printf("! %d\n",t);fflush(stdout);
		return 0;
	}
	mset(r,-1);
	if(n%2==0){
		for(int i=n-1;i>=0;--i){
			int pt=t;
			while(!ask(i,i+1))pt=t;
			int d=0; // que cambio
			fore(j,i+1,n){
				if((r[j]^w[j])==1)d++;
				else d--;
			}
			if(pt+d<t){ // era 0, ahora es 1
				r[i]=1^w[i];
			}
			else if(pt+d>t){ // era 1, ahora es 0
				r[i]=w[i];
			}
			else {assert(0);}
		}
	}
	else {
		int pt=t;
		while(!ask(1,n))pt=t;
		if(n-pt>t){
			r[0]=w[0];
		}
		else if(n-pt<t){
			r[0]=1^w[0];
		}
		else {assert(0);}
		fore(i,1,n){
			int pt=t;
			while(ask(i-1,i+1))pt=t;
			int d=0; // que cambio
			fore(j,0,i){
				if((r[j]^w[j])==1)d++;
				else d--;
			}
			if(pt+d<t){ // era 0, ahora es 1
				r[i]=1^w[i];
			}
			else if(pt+d>t){ // era 1, ahora es 0
				r[i]=w[i];
			}
			else {assert(0);}
		}
	}
	printf("! ");
	fore(i,0,n)printf("%d",r[i]);
	puts("");fflush(stdout);
	return 0;
}