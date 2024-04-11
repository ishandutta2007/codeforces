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
char s[200005];
int x,y;
int sx[200005],sy[200005];

bool can(int k){
	fore(i,0,n-k+1){
		int xx=sx[n]-(sx[i+k]-sx[i]);
		int yy=sy[n]-(sy[i+k]-sy[i]);
		if(abs(xx-x)+abs(yy-y)<=k)return true;
	}
	return false;
}

int main(){
	scanf("%d%s%d%d",&n,s,&x,&y);
	fore(i,0,n){
		sx[i+1]=sx[i];sy[i+1]=sy[i];
		if(s[i]=='U')sy[i+1]++;
		else if(s[i]=='D')sy[i+1]--;
		else if(s[i]=='R')sx[i+1]++;
		else if(s[i]=='L')sx[i+1]--;
		else {assert(0);}
	}
	if(abs(x+y)%2!=n%2||!can(n)){puts("-1");return 0;}
	int a=0,b=n+1;
	while(b-a>1){
		int m=(a+b)/2;
		if(can(m-1))b=m;
		else a=m;
	}
	printf("%d\n",a);
	return 0;
}