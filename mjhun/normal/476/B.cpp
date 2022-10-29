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
#define mset(x,a) (memset((x),(a),sizeof(x)))
#define mcpy(x,y) (memcpy((x),(y),sizeof(x)))
using namespace std;
typedef long long ll;

int c[16][16];
char s[16];
int o,x,z;

int main(){
	fore(i,0,16){
		c[i][0]=c[i][i]=1;
		fore(j,1,i)c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	scanf("%s",s);
	for(int i=0;s[i];++i){
		if(s[i]=='+')o++;
		else o--;
	}
	scanf("%s",s);
	for(int i=0;s[i];++i){
		if(s[i]=='+')x++;
		else if(s[i]=='-')x--;
		else z++;
	}
	int t=abs(o-x);
	if(t>z){puts("0");return 0;}
	printf("%.12lf\n",1.*c[z][(t+z)/2]/(1<<z));
	return 0;
}