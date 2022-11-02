#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int>Q;
const int N=200002;
int n,k,i,a[N];
int main(){
	scanf("%d%d",&n,&k);
	if(n<k){
		printf("NO");
		return 0;
	}
	while(n)
		Q.push(n&-n),n&=n-1;
	if(Q.size()>k){
		printf("NO");
		return 0;
	}
	while(Q.size()<k){
		n=Q.top()/2;
		Q.pop();
		Q.push(n);
		Q.push(n);
	}
	for(i=k;i;i--)
		a[i]=Q.top(),Q.pop();
	printf("YES\n");
	for(i=1;i<=k;i++)
		printf("%d ",a[i]);
}