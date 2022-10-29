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

int gcd(int a, int b){
	while(b){
		int c=a%b;
		a=b;b=c;
	}
	return a;
}

int n,a[705];
bool b[705][705];
bool f0[705][705];
bool f1[705][705];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i);
	fore(i,0,n)fore(j,0,n)b[i][j]=gcd(a[i],a[j])>1;
	fore(i,0,n)f0[0][i]=f1[0][i]=true;
	fore(l,1,n+1){
		fore(i,l,n){
			fore(j,i-l,i)if(b[i][j])f0[l][i]|=f0[j-(i-l)][j]&f1[i-j-1][j];
		}
		fore(i,0,n-l){
			fore(j,i+1,i+l+1)if(b[i][j])f1[l][i]|=f0[j-i-1][j]&f1[i+l-j][j];
		}
	}
	fore(i,0,n)if(f0[i][i]&&f1[n-1-i][i]){puts("Yes");return 0;}
	puts("No");
	/*while(1){
		int t,i;
		scanf("%d%d",&t,&i);
		if(t==0){
			fore(l,0,n+1)if(f0[l][i])printf(" %d",l);puts("");
		}
		else {
			fore(l,0,n+1)if(f1[l][i])printf(" %d",l);puts("");
		}
	}*/
	return 0;
}