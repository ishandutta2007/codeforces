#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n,a[N];ll s;priority_queue<ll> q;
void solve(){
	scanf("%d",&n),s=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s+=a[i];
	sort(a+1,a+n+1,greater<int>());
	while(!q.empty())q.pop();
	q.push(s);int t=1;
	while(!q.empty()){
		ll x=q.top();q.pop();
		if(x==a[t]){t++;continue;}
		if(x<a[t]){printf("NO\n");return;}
		q.push(x+1>>1),q.push(x>>1);
	}
	printf("YES\n");
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}