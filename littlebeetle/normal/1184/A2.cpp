#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
int n,i,j,g[N],ans;
char s[N];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
bool check(int x){
	int i,j,p;
	for(i=1;i<=x;i++){
		p=0;
		for(j=i;j<=n;j+=x)
			p^=s[j]-48;
		if(p)
			return 0;
	}
	return 1;
}
int main(){
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++)
		g[i]=gcd(i,n);
	for(i=1;i<=n;i++)
		if(g[i]==i&&check(i))
			for(j=i;j<=n;j+=i)
				if(g[j]==i)
					ans++;
	printf("%d",ans);
			
}