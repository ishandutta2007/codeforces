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

int n,k;
int r[32],s;

int main(){
	scanf("%d%d",&n,&k);
	fore(i,0,30)if(n&(1<<i))r[i]++,s++;
	if(n<k||s>k){puts("NO");return 0;}
	puts("YES");
	while(s<k){
		for(int i=29;i;--i)if(r[i]){r[i]--;r[i-1]+=2;break;}
		s++;
	}
	bool p=false;
	fore(i,0,30)fore(_,0,r[i]){
		if(p)putchar(' ');
		p=true;
		printf("%d",1<<i);
	}
	puts("");
	return 0;
}