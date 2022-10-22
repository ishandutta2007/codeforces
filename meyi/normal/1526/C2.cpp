#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int a,ans,n;
ll sum;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		if(sum+a>=0)sum+=a,q.push(a);
		else if(q.size()&&a>q.top()){
			sum-=q.top();
			q.pop();
			sum+=a;
			q.push(a);
		}
		ans=max(ans,(int)q.size());
	}
	printf("%d",ans);
	return 0;
}