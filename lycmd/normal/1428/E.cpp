#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
int calc(int x,int y){
	return (x%y)*(x/y+1)*(x/y+1)+(y-x%y)*(x/y)*(x/y);
}
struct node{
	int cnt,val,tim;
	int operator<(const node&r)const{
		return tim-calc(val,cnt+1)<r.tim-calc(r.val,r.cnt+1);
	}
};
priority_queue<node>q;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;cin>>x;q.push({1,x,x*x});
	}
	for(int i=k-n;i--;){
		node t=q.top();q.pop();
		t.tim=calc(t.val,++t.cnt);q.push(t);
	}
	for(int i=1;i<=n;i++)
		ans+=q.top().tim,q.pop();
	cout<<ans<<"\n";
}