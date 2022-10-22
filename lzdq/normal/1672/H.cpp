#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN=2e5+5;
int n,q;
char s[MAXN];
int sum[MAXN][2];
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	for(int i=1; i<=n; i++){
		s[i]-='0';
		sum[i][0]=sum[i-1][0];
		sum[i][1]=sum[i-1][1];
		if(i>1&&s[i]==s[i-1]) sum[i][s[i]]++;
	}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int x=sum[r][0]-sum[l][0],y=sum[r][1]-sum[l][1];
		printf("%d\n",max(x,y)+1);
	}
	return 0;
}