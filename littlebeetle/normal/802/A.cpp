#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N=500002;
int n,k,p,i,in[N],a[N],id[N],nxt[N],cnt,opt[N];
struct good{
	int num,val;
	bool operator<(const good &k)const{
		return k.val>val;
	}
}x;
priority_queue<good>Q;
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=n;i++)
		id[i]=n+1;
	for(i=n;i;i--){
		nxt[i]=id[a[i]];
		id[a[i]]=i;
	}
	for(i=1;i<=n;i++)
		if(!in[a[i]]){
			if(Q.size()==k){
				x=Q.top();
				Q.pop();
				in[x.num]=0;
			}
			in[a[i]]=1;
			cnt++;
			Q.push((good){a[i],nxt[i]});
		}
		else
			Q.push((good){a[i],nxt[i]}),
			k++;
	printf("%d",cnt);
	return 0;
}