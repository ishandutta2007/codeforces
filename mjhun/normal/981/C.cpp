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

int d[100005];
int n;
vector<int> l;

int main(){
	scanf("%d",&n);
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		d[x]++;d[y]++;
	}
	int k=-1;
	fore(i,0,n){
		if(d[i]==1)l.pb(i);
		else if(d[i]>2){
			if(k<0)k=i;
			else {puts("No");return 0;}
		}
	}
	puts("Yes");
	if(k<0){
		assert(SZ(l)==2);
		printf("1\n%d %d\n",l[0]+1,l[1]+1);
	}
	else {
		printf("%d\n",SZ(l));
		for(int x:l)printf("%d %d\n",k+1,x+1);
	}
	return 0;
}