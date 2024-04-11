#include<bits/stdc++.h>
using namespace std;
const int N=4000100;
int n,m,a[N],sum;
int c[N];
int main(){
	scanf("%d%d",&n,&m);
	a[n]=1;
	for(int i=n;i>=1;i--){
		a[i]=(a[i]+sum)%m;
		for(int o=2;o<=n;o++){
			if(i*o>n)break;
			a[i]=((a[i]+c[i*o])%m-((i+1)*o<=n?c[(i+1)*o]:0)+m)%m;
		}
		sum=(sum+a[i])%m;
		c[i]=(c[i+1]+a[i])%m;
	}
	printf("%d\n",a[1]);
}