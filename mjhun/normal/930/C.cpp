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
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int m,n;
int x[100005];
int l0[100005],l1[100005]; // mayor secuencia que contiene
int mn[100005]; // min valor

void doit(int *l){
	mn[0]=-1;
	fore(i,1,n+1)mn[i]=1<<30;
	fore(i,0,n){
		int k=upper_bound(mn,mn+n+1,x[i])-mn;
		mn[k]=min(mn[k],x[i]);
		l[i]=k;
	}
}

int main(){
	scanf("%d%d",&m,&n);
	fore(i,0,m){
		int l,r;
		scanf("%d%d",&l,&r);l--;
		x[l]++;x[r]--;
	}
	fore(i,1,n)x[i]+=x[i-1];
	doit(l0);
	//fore(i,0,n)printf(" %d",l0[i]);puts("");
	reverse(x,x+n);
	doit(l1);
	reverse(l1,l1+n);
	int r=0;
	fore(i,0,n)r=max(r,l0[i]+l1[i]-1);
	printf("%d\n",r);
	return 0;
}