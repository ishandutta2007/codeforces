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
int l[1024],r[1024];
int l2[1024],r2[1024];
int a[1024];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",l+i);
	fore(i,0,n)scanf("%d",r+i);
	int t=n,q=0;
	while(q<n){
		bool b=false;
		mcpy(l2,l);mcpy(r2,r);
		fore(i,0,n)if(l[i]==0&&r[i]==0){
			b=true;q++;
			a[i]=t;
			l2[i]=r2[i]=-1;
			fore(j,0,n){
				if(j<i)r2[j]--;
				else l2[j]--;
			}
		}
		mcpy(l,l2);mcpy(r,r2);
		if(!b){puts("NO");return 0;}
		t--;
	}
	puts("YES");
	fore(i,0,n)printf("%d%c",a[i]," \n"[i==n-1]);
	return 0;
}