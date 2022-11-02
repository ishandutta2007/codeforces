#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1000020;
struct Uzi{
	int t,b;
	bool operator<(const Uzi &k)const{
		return k.b<b;
	}
}a[N];
int n,k,i;
long long sum,ans;
priority_queue<int,vector<int>,greater<int> >Q;
void init(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d%d",&a[i].t,&a[i].b);
	sort(a+1,a+n+1);
}
void work(){
	for(i=1;i<=n;i++){
		Q.push(a[i].t);
		sum+=a[i].t;
		if(Q.size()>k){
			sum-=Q.top();
			Q.pop();
		}
		ans=max(ans,sum*a[i].b);
	}
	printf("%lld",ans);
}
int main(){
	init();
	work();
	//while(1);
	return 0;
}