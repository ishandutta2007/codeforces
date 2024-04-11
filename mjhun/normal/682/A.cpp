#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int q0[8],q1[8];

void doit(int n, int *q){
	fore(i,1,6)q[i]+=n/5;
	fore(i,1,n%5+1)q[i]++;
	q[0]=q[5];
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	doit(n,q0);doit(m,q1);
	ll r=0;
	fore(i,0,5)r+=1LL*q0[i]*q1[5-i];
	printf("%lld\n",r);
	return 0;
}