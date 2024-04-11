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

int n,m,a[128],b[128];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i);
	scanf("%d",&m);
	fore(i,0,m)scanf("%d",b+i);
	sort(a,a+n);sort(b,b+m);
	int r=0,i=0,j=0;
	while(i<n&&j<m){
		if(abs(a[i]-b[j])<=1)r++,i++,j++;
		else if(a[i]<b[j])i++;
		else j++;
	}
	printf("%d\n",r);
	return 0;
}