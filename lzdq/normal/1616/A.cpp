#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
int n,cnt[105];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=0; i<=100; i++)
			cnt[i]=0;
		while(n--){
			int a;
			scanf("%d",&a);
			cnt[abs(a)]++;
		}
		int ans=min(cnt[0],1);
		for(int i=1; i<=100; i++)
			ans+=min(cnt[i],2);
		printf("%d\n",ans);
	}
	return 0;
}