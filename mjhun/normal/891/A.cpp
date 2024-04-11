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

int n;
int x[2048];

int main(){
	scanf("%d",&n);
	int q=0;
	fore(i,0,n)scanf("%d",x+i),q+=x[i]==1;
	if(q){printf("%d\n",n-q);return 0;}
	int r=(1<<30);
	fore(i,0,n){
		int k=x[i];
		int j=i+1;
		while(k>1&&j<n){
			k=__gcd(k,x[j]);
			j++;
		}
		if(k==1)r=min(r,j-i);
	}
	if(r==(1<<30)){puts("-1");return 0;}
	printf("%d\n",r-1+n-1);
	return 0;
}