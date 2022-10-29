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

char s[8];
char t[8];

int main(){
#ifdef DEMETRIO
	freopen("bin","r",stdin);
#endif
	while(scanf("%s",s)!=EOF){
		fore(i,0,6)s[i]-='0';
		int r=6;
		fore(i,0,1000000){
			int k=i;
			fore(j,0,6)t[j]=k%10,k/=10;
			if(t[0]+t[1]+t[2]!=t[3]+t[4]+t[5])continue;
			int rr=0;
			fore(j,0,6)rr+=s[j]!=t[j];
			r=min(r,rr);
		}
		printf("%d\n",r);

		puts("");
	}
	return 0;
}