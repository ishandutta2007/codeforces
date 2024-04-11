#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000002;
int q,n,i,s[N],a,x[N],m,ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			s[i]=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a);
			s[a]++;
		}
		m=0;
		for(i=1;i<=n;i++)
			if(s[i])
				x[++m]=s[i];
		sort(x+1,x+m+1,cmp);
		ans=0;
		x[0]=1<<30;
		for(i=1;i<=m;i++){
			if(x[i]>=x[i-1])
				x[i]=x[i-1]-1;
			if(x[i]>=0)
				ans+=x[i];
		}
		printf("%d\n",ans);
	}
}