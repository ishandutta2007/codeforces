#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=5005;
int n,a[MAXN];
int s[MAXN][MAXN];
ll ans;
int Query(int x1,int x2,int y1,int y2){
	return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(a[i]>a[j]);
		ans=0;
		for(int i=1; i<n; i++)
			for(int j=i+2; j<n; j++)
				if(a[i]<a[j]) ans+=Query(i+1,j-1,j+1,n);
		printf("%lld\n",ans);
	}
	return 0;
}