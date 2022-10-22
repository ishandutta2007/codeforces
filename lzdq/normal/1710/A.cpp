#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,m,k,a[MAXN];
bool Check(int n,int m){
	ll sum=0,cnt=0;
	for(int i=1; i<=k; i++){
		int t=a[i]/n;
		if(t>=2){
			sum+=t;
			if(t>2) cnt++;
		}
	}
	if(sum<m) return 0;
	if(!cnt&&(sum-m)&1) return 0;
	return 1;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1; i<=k; i++)
			scanf("%d",a+i);
		if(Check(n,m)||Check(m,n)) puts("Yes");
		else puts("No");
	}
	return 0;
}