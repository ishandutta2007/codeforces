#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
struct node{
	int val,id;
	inline bool operator<(const node &k)const{
		return val<k.val;
	}
}a[maxn];
int lst,n,p,t;
ll sum[maxn];
inline int half(ll k){
	int ans=0,l=0,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(k>=a[mid].val)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(a,0,sizeof a);
		for(ri i=1;i<=n;++i)scanf("%d",&a[i].val),a[i].id=i;
		sort(a+1,a+n+1);
		memset(sum,0,sizeof sum);
		for(ri i=1;i<=n;++i)sum[i]=sum[i-1]+a[i].val;
		for(ri i=1;i<=n;++i){
			register ll tmp=sum[i];
			lst=i,p=half(tmp);
			while(lst!=p){
				tmp+=sum[p]-sum[lst];
				lst=p;
				p=half(tmp);
			}
			if(p==n)q.push(a[i].id);
		}
		printf("%d\n",q.size());
		while(q.size())printf("%d ",q.top()),q.pop();
		printf("\n");
	}
	return 0;
}