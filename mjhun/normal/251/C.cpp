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

#define M 360360

ll b,a,r;int k;
int d0[M+5],d1[M+5];

void sim(){
	assert(a<=b);
	while(b>a){
		ll w=b-1;
		fore(i,2,k+1)if(b/i*i>=a)w=min(w,b/i*i);
		b=w;r++;
	}
}

int main(){
	scanf("%lld%lld%d",&b,&a,&k);
	memset(d0,-1,sizeof(d0));d0[b%M]=d1[b%M]=0;
	while(1){
		ll w=b-1;
		fore(i,2,k+1)w=min(w,b/i*i);
		if(w<=a){sim();break;}
		if(d0[w%M]>=0){
			int l0=d0[b%M]-d0[w%M]+1,l1=d1[b%M]-d1[w%M]+b-w;
			ll nc=(w-a)/l1;
			r+=nc*l0;
			b-=nc*l1;
			sim();
			break;
		}
		d0[w%M]=d0[b%M]+1;d1[w%M]=d1[b%M]+b-w;
		b=w;r++;
	}
	printf("%lld\n",r);
	return 0;
}