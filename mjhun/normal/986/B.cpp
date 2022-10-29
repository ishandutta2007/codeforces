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
int a[1<<20];
bool vis[1<<20];
int r;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i),a[i]--;
	fore(i,0,n)if(!vis[i]){
		int j=i,t=1;
		while(!vis[j]){
			t^=1;
			vis[j]=true;
			j=a[j];
		}
		r^=t;
	}
	puts((r^(n&1))?"Um_nik":"Petr");
	return 0;
}