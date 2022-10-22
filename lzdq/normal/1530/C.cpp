#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e6;
int n,a[MAXN],b[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		for(int i=1; i<=n; i++)
			scanf("%d",b+i);
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		reverse(a+1,a+n+1);
		reverse(b+1,b+n+1);
		int k=n-n/4,s1=0,s2=0;
		for(int i=1; i<=k; i++)
			s1+=a[i],s2+=b[i];
		int ans=0;
		reverse(a+1,a+n+1);
		for(int i=2; i<=n; i++)
			a[i]+=a[i-1],b[i]+=b[i-1];
		while(s1<s2){
			ans++;
			n++;
			a[n]=a[n-1]+100;
			b[n]=b[n-1];
			s1=a[n]-a[n/4];
			s2=b[n-n/4];
		}
		printf("%d\n",ans);
	}
	return 0;
}