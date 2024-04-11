#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
int a[maxn],n,t;
queue<int>q1,q2;
int main(){
	scanf("%d",&t);
	a[0]=-1;
	while(t--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		sort(a+1,a+n+1);
		for(ri i=1;i<=n;++i)
			if(a[i]!=a[i-1])
				q1.push(a[i]);
			else q2.push(a[i]);
		while(q1.size())printf("%d ",q1.front()),q1.pop();
		while(q2.size())printf("%d ",q2.front()),q2.pop();
		printf("\n");
	}
	return 0;
}