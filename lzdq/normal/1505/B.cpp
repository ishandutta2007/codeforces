#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m,a[MAXN];
int ans;
int main(){
	scanf("%d",&n);
	while(n>=10){
		m=0;
		while(n){
			m+=n%10;
			n/=10;
		}
		n=m;
	}
	printf("%d\n",n);
	return 0;
}