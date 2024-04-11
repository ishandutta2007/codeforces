#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

struct dn{int x,y;}a[200001];
bool operator<(dn u,dn v){
	return v.y!=u.y?u.y<v.y:u.x<v.x;
}
bool cmp(dn u,dn v){
	return u.x!=v.x?u.x<v.x:u.y<v.y;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].x);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].y);
	sort(a+1,a+n+1,cmp);
	int o=1,cur=-1;
	priority_queue<dn>q;
	long long sum=0,ans=0;
	while(1){
		if(q.empty()){
			if(o>n)break;
			cur=a[o].x;
			q.push(a[o]);
			sum+=a[o].y;
			o++;
		}
		while(o<=n&&a[o].x==cur){
			q.push(a[o]);
			sum+=a[o].y;
			o++;
		}
		dn w=q.top();
		q.pop();
		sum-=w.y;
		ans+=sum;
		cur++;
		//printf("%d %d %lld\n",w.x,w.y,sum);
	}
	printf("%lld\n",ans);
}