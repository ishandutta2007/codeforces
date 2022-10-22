#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
queue<int>q[2];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			q[a[i]&1].push(a[i]);
		}
		while(q[0].size())printf("%d ",q[0].front()),q[0].pop();
		while(q[1].size())printf("%d ",q[1].front()),q[1].pop();
		puts("");
	}
	return 0;
}