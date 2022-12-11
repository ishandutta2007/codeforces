#include<cstdio>

using namespace std;

long long a[1000001];
int s[1000001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	for(int i=0;i<=n;i++){
		while(s[0]>1&&1ll*(i-s[s[0]-1])*(a[s[s[0]]]-a[s[s[0]-1]])>=1ll*(s[s[0]]-s[s[0]-1])*(a[i]-a[s[s[0]-1]]))s[0]--;
		s[++s[0]]=i;
	}
	for(int i=1;i<s[0];i++){
		double w=(double)(a[s[i+1]]-a[s[i]])/(s[i+1]-s[i]);
		for(int j=s[i]+1;j<=s[i+1];j++)
			printf("%.20f\n",w);
	}
}