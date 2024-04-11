#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		int mn=1000000001,mx=0,smn=1000000001,smx=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]<mn)
				smn=mn,mn=a[i];
			else if(a[i]<smn)
				smn=a[i];
			if(a[i]>mx)
				smx=mx,mx=a[i];
			else if(a[i]>smx)
				smx=a[i];
		}
		printf("%lld\n",0ll+mx-mn+smx-smn);
	}
	return 0;
}