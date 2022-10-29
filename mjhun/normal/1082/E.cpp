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

int n,c;
int a[1<<19];
int s0[1<<19],s1[1<<19];
int mm[1<<19],p[1<<19];

int main(){
	mset(p,-1);
	scanf("%d%d",&n,&c);
	fore(i,0,n){
		scanf("%d",a+i);
		s0[i+1]=s0[i]+(a[i]==c);
		if(p[a[i]]<0)s1[i+1]=1;
		else s1[i+1]=s1[p[a[i]]+1]+1;
		p[a[i]]=i;
	}
	fore(i,0,(1<<19))mm[i]=-(1<<20);
	int r=s0[n];
	for(int i=n-1;i>=0;--i){
		mm[a[i]]=max(mm[a[i]],s1[i+1]-s0[i+1]);
		r=max(r,s0[i]-(s1[i+1]-1)+mm[a[i]]+s0[n]);
	}
	printf("%d\n",r);
	return 0;
}