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

int n;ll k,s;
int r[300005];

int main(){
	scanf("%d%lld",&n,&k);
	fore(i,0,n)r[i]=1,s+=i;
	if(s<k)puts("Impossible");
	else {
		for(int i=n-1;i>0;--i){
			assert(r[i]==1);
			if(s-k<=i){
				r[i]--;
				r[i-(s-k)]++;
				s=k;
				break;
			}
			else {
				r[i]--;
				r[0]++;
				s-=i;
			}
		}
		assert(s==k);
		int q=0;
		//fore(i,0,n)printf("%d\n",r[i]);
		fore(i,0,n+1){
			if(!r[i]){
				q=i;
				break;
			}
			//printf("%d%d",i,r[i]);
			fore(_,0,r[i]-1)printf("()");
			printf("(");
		}
		fore(i,0,q)printf(")");
		puts("");
	}
	return 0;
}