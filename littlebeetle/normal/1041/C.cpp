#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=200002;
struct p{
	int a,id;
	bool operator<(const p &d)const{
		return d.a>a;
	}
}f[N];
struct q{
	int a,x;
	bool operator<(const q &d)const{
		return d.a<a;
	}
}t;
priority_queue<q>Q;
int n,m,k,i,ans[N],cnt;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
		scanf("%d",&f[i].a),f[i].id=i;
	sort(f+1,f+n+1);
	for(i=1;i<=n;i++){
		if(!Q.empty()&&(Q.top()).a+k<f[i].a){
			t=Q.top();
			Q.pop();
			ans[f[i].id]=t.x;
			Q.push((q){f[i].a,t.x});
		}
		else{
			ans[f[i].id]=++cnt;
			Q.push((q){f[i].a,cnt});
		}
	}
	printf("%d\n",cnt);
	for(i=1;i<=n;i++)
		printf("%d ",ans[i]);
}