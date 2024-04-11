#include<cstdio>
#include<queue>
using namespace std;
int n,a;
long long ans;
struct p{
	int x,y;
	bool operator<(const p &k)const{
		if(k.x!=x)
			return k.x<x;
		return k.y<y;
	}
}o;
priority_queue<p>Q;
int main(){
	Q.push((p){1<<30,1<<30});
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		o=Q.top();
		if(a>o.x){
			Q.pop();
			ans+=a-o.x;
			Q.push((p){a,o.y});
			if(o.x!=o.y)
				Q.push((p){o.x,o.x});
		}
		else
			Q.push((p){a,a});
	}
	printf("%I64d",ans);
}