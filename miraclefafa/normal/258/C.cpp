#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
const int p=1e9+7;
int n,a[1010000],pc[10100],ans;
vector<int> y;
long long Pow(long long a,int b) {
	long long res=1;
	for (int i=0;b>>i;i++) {
		if ((b>>i)&1) res=res*a%p;
		a=a*a%p;
	}
	return res;
}
long long cow(long long cnt,long long k) {
	long long t=Pow(cnt-1,k),c=1ll*cnt*Pow(cnt-1,p-2)%p;
	if (k==0) return 1;
	if (c==1) return (k+1)*t%p; else return t*(Pow(c,k+1)-1)%p*Pow(c-1,p-2)%p;
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	sort(a,a+n);
	for (int i=a[n-1];i>0;i--) {
		int d=lower_bound(a,a+n,i)-a;
		y.clear();
		for (int j=1;j*j<=i;j++) if (i%j==0) {
			y.push_back(j);if (j*j!=i) y.push_back(i/j);
		}
		long long t;
		if (y.size()==1) t=1; else t=cow(y.size(),n-d-1)%p;
		sort(y.begin(),y.end());
		for (int j=0;j<y.size();j++) pc[j+1]=lower_bound(a,a+n,y[j])-a+1;
		for (int j=1;j<y.size();j++) t=t*Pow(j,pc[j+1]-pc[j])%p;
		ans=(ans+t)%p;
	}
	if (ans<0) ans+=p;
	printf("%d\n",ans);
}