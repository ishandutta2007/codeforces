#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=2005;
int n,a[MAXN];
int ans;
int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		ans=0;
		for(int i=1; i<=n; i++)
			for(int j=1; j<i; j++){
				int x=a[i],y=a[j];
				if(x%2==0||y%2==0) ans++;
				else if(gcd(x,y)>1) ans++;
			}
		printf("%d\n",ans);
	}
	return 0;
}