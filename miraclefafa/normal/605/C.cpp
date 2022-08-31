#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
typedef long double LD;
const int N=101000;
int n,p,q,a[N],b[N];
LD ff(LD x) {
	LD mv=1;
	rep(i,0,n) mv=min(mv,(1-b[i]*x)/a[i]);
	return mv*p+x*q;
}
int main() {
	scanf("%d%d%d",&n,&p,&q);
	rep(i,0,n) scanf("%d%d",a+i,b+i);
	LD l=0,r=1; r/=*max_element(b,b+n);
	rep(i,0,200) {
		LD fl=(l+l+r)/3,fr=(r+r+l)/3;
		if (ff(fl)>ff(fr)) r=fr; else l=fl;
	}
	printf("%.10f\n",(double)ff((l+r)/2));
}