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
char s[16];
int q[16],z[16];
pair<int,int> x[16];

int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%s",s);int l=strlen(s);
		int k=1;
		for(int i=l-1;i>=0;--i){
			q[s[i]-'a']+=k;
			k*=10;
		}
		z[s[0]-'a']=1;
	}
	fore(i,0,10)x[i]=mp(q[i],z[i]);
	sort(x,x+10);reverse(x,x+10);
	int r=0,d=1,u=0;
	fore(i,0,10){
		if(!u&&!x[i].snd)u=1;
		else r+=x[i].fst*(d++);
	}
	printf("%d\n",r);
	return 0;
}