#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m,a[N],t[N],tx,lst;ll sum;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
	for(int i=1,op,p,x;i<=m;i++){
		scanf("%d",&op);
		if(op==1){scanf("%d%d",&p,&x),sum+=x-(lst>t[p]?tx:a[p]),a[p]=x,t[p]=i;}
		else scanf("%d",&x),sum=1ll*n*x,lst=i,tx=x;
		printf("%lld\n",sum);
	}
	return 0;
}