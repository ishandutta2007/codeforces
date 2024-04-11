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

int a[300005];
int c[64],c2[64];
int n;

int main(){
	while(scanf("%d",&n)!=EOF){
		fore(i,0,n)scanf("%d",a+i),a[i]/=100;
		c[0]=0;
		fore(i,1,64)c[i]=1<<30;
		fore(i,0,n){
			fore(j,0,64)c2[j]=1<<30;
			fore(j,0,64){
				fore(k,0,min(j,a[i])+1){
					if(k==0&&j+a[i]/10>=64)continue;
					if(k==0)c2[j+a[i]/10]=min(c2[j+a[i]/10],c[j]+a[i]);
					else c2[j-k]=min(c2[j-k],c[j]+a[i]-k);
				}
			}
			memcpy(c,c2,sizeof(c));
		}
		int r=1<<30;
		fore(i,0,64)r=min(r,c[i]);
		printf("%d\n",r*100);
		puts("");
	}
	return 0;
}