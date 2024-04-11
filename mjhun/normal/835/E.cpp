#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int n,x,y;

int ask(int m, int v){
	int q=0;
	fore(i,0,n)if((i&m)==v)q++;
	assert(q);
	printf("? %d",q);
	fore(i,0,n)if((i&m)==v)printf(" %d",i+1);
	puts("");fflush(stdout);
	int r;
	scanf("%d",&r);
	return r!=(x*(q%2));
}

int r0,r1;

int main(){
	scanf("%d%d%d",&n,&x,&y);
	int k=0;
	for(;!ask(1<<k,0);++k);
	r0=1<<k;int m=1<<k;
	fore(i,0,10){
		if(i==k)continue;
		if(r0+(1<<i)>=n)break;
		m|=1<<i;
		if(ask(m,r0|(1<<i))){
			r0|=1<<i;
		}
	}
	r1=0;m=1<<k;
	fore(i,0,k){
		if(r0&(1<<i))r1|=(1<<i);
		m|=1<<i;
	}
	fore(i,k+1,10){
		if(r1+(1<<i)>=n)break;
		m|=1<<i;
		if(ask(m,r1|(1<<i))){
			r1|=1<<i;
		}
	}
	if(r0>r1)swap(r0,r1);
	printf("! %d %d\n",r0+1,r1+1);fflush(stdout);
	return 0;
}