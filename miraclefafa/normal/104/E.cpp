#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
struct Que{
	int a,b,w;
}Q[300010];
bool operator <(Que a,Que b) {
	return a.b<b.b;
}
int n,i,m,Lim,j;
long long ans[301000],w[301000],s[301000];
int main() {
//freopen("data.in","r",stdin);
	scanf("%d",&n);
	for (i=0;i<n;i++) scanf("%I64d",&w[i]);
	scanf("%d",&m);
	for (i=0;i<m;i++) scanf("%d%d",&Q[i].a,&Q[i].b),Q[i].a--,Q[i].w=i;
	sort(Q,Q+m);
	Lim=(int)sqrt(n);
	for (i=0;i<m;i++) {
		if (Q[i].b>Lim) {
			long long tmp=0;
			for (j=Q[i].a;j<n;j+=Q[i].b) tmp+=w[j];
			ans[Q[i].w]=tmp;
		} else {
			memset(s,0,sizeof(s));
			for (j=n-1;j>=0;j--) s[j]=w[j]+s[j+Q[i].b];
			j=i;
			do {
				ans[Q[j].w]=s[Q[j].a];
				j++;
			} while (Q[j].b==Q[j-1].b);
			i=j-1;
		}
	}
	for (i=0;i<m;i++) printf("%I64d\n",ans[i]);
}