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

bitset<200000005> w;

int doit(int x){
	if(x==0)return 0;
	int r=1;
	if(x<0)r*=-1,x*=-1;
	for(int i=2;i*i<=x;++i){
		int q=0;
		while(x%i==0){
			q^=1;x/=i;
		}
		if(q)r*=i;
	}
	r*=x;
	return r;
}

int n;
ll a[5005];
int r[5005];

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int x;
		scanf("%d",&x);
		a[i]=doit(x)+100000001;
	}
	int rr=0;
	fore(i,0,n){
		rr=0;w[100000001]=1;
		fore(j,i,n){
			if(!w[a[j]])w[a[j]]=1,rr++;
			r[rr]++;
		}
		fore(j,i,n)w[a[j]]=0;
	}
	r[1]+=r[0];
	fore(i,1,n+1)printf("%d%c",r[i]," \n"[i==n]);
	return 0;
}