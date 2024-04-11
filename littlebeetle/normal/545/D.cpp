#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100002;
int n,t[N],i,p;
long long s;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",t+i);
	sort(t+1,t+n+1);
	for(i=1;i<=n;i++){
		if(s<=t[i])
			p++,s+=t[i];
	}
	printf("%d",p);
}