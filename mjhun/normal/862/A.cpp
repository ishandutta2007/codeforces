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

int n,x;
int a[128];
bool h[128];

int main(){
	scanf("%d%d",&n,&x);
	int r=0;
	fore(i,0,n){
		scanf("%d",a+i);
		h[a[i]]=1;
		if(a[i]==x)r++;
	}
	fore(i,0,x)r+=!h[i];
	printf("%d\n",r);
	return 0;
}