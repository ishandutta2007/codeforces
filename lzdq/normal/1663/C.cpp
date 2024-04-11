#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN],sum;
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i),sum+=a[i];
	printf("%d\n",sum);
	return 0;
}