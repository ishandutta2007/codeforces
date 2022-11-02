#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=200002;
priority_queue<int,vector<int>,greater<int> >Q,P;
int n,z,i,a[N],ans;
int main(){
	scanf("%d%d",&n,&z);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
		if(Q.empty()||Q.top()>a[i]-z){
			if(!P.empty()){
				Q.push(P.top());
				P.pop();
				P.push(a[i]);
			}
			else
				Q.push(a[i]);
		}
		else
			Q.pop(),P.push(a[i]),ans++;
	printf("%d",ans);
	return 0;
}