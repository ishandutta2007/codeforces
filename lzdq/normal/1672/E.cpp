#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int n,ans;
int Ask(int w){
	printf("? %d\n",w);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
int main(){
	scanf("%d",&n);
	int l=n,r=2000*n;
	while(l<r){
		int mid=l+r>>1;
		int t=Ask(mid);
		//int t=(mid>=33);
		if(t==1) r=mid;
		else l=mid+1;
	}
	ans=l;
	for(int i=1; i<=n; i++){
		int w=(ans-1)/i;
		if(!w) break;
		int t=Ask(w);
		if(t) ans=min(ans,t*w);
	}
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}
//glory,to,ukraine,and,anton,trygub