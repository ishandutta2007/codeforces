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
char s[2048];
int j;

void doit(char c){
	fore(i,j,n)if(s[i]==c){
		printf("%d %d\n",j+1,i+1);
		reverse(s+j,s+i+1);
		break;
	}
	j++;
}

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		scanf("%d%d%s",&n,&k,s);
		printf("%d\n",n);
		j=0;
		fore(i,0,n/2-k+1)doit('(');
		fore(i,0,n/2-k+1)doit(')');
		fore(i,0,k-1)doit('('),doit(')');
	}
	return 0;
}