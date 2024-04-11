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

int n,d,b;
int s[100005];

bool can(int k){
	fore(i,k,(n+1)/2){
		int e=min(i+1LL*(i+1)*d+1,1LL*n);
		if(s[e]<b*(i-k+1))return false;
	}
	for(int i=n-k-1;i>=(n+1)/2;--i){
		int ss=max(i-1LL*(n-i)*d,0LL);
		if(s[n]-s[ss]<b*(n-k-i))return false;
	}
	return true;
}

int main(){
	scanf("%d%d%d",&n,&d,&b);
	fore(i,0,n)scanf("%d",s+i+1);
	fore(i,0,n)s[i+1]+=s[i];
	int ss=0,e=(n+1)/2+1;
	while(e-ss>1){
		int m=(ss+e)/2;
		if(can(m-1))e=m;
		else ss=m;
	}
	printf("%d\n",ss);
	return 0;
}