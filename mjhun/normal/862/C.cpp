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
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int n,x;

int main(){
	scanf("%d%d",&n,&x);
	if(n==1)printf("YES\n%d\n",x);
	else if(n==2){
		if(x==0)puts("NO");
		else printf("YES\n%d %d\n",0,x);
	}
	else {
		vector<int> r;
		int xx=x;
		fore(i,0,n-3){
			x^=i;
			r.pb(i);
		}
		r.pb(x|(1<<17));
		r.pb((1<<17)|(1<<18));
		r.pb(1<<18);
		puts("YES");
		int s=0;
		fore(i,0,r.size()){
			if(i)putchar(' ');
			printf("%d",r[i]);
			s^=r[i];
		}
		puts("");
		assert(s==xx);
	}
	return 0;
}