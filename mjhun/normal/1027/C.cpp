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
int c[10005];
int a[1<<20];
vector<int> z;

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		z.clear();
		scanf("%d",&n);
		fore(i,0,n){
			scanf("%d",a+i);
			c[a[i]]++;
			if(c[a[i]]==2)z.pb(a[i]);
		}
		sort(z.begin(),z.end());
		int ra=0,rb=1,t=0;
		for(int x:z){
			if(c[x]>=4){ra=rb=x;break;}
			else if(x*ra<t*rb)ra=t,rb=x;
			t=x;
		}
		printf("%d %d %d %d\n",ra,ra,rb,rb);
		fore(i,0,n)c[a[i]]--;
	}
	return 0;
}