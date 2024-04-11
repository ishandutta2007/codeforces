#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,a[N];
bool no1(){for(int i=1;i<=n;i++)if(a[i]==1)return 0;return 1;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		if(no1()){printf("Yes\n");continue;}
		sort(a+1,a+n+1);int m=unique(a+1,a+n+1)-a-1;
		bool flag=1;
		for(int i=1;i<n;i++)if(a[i+1]-a[i]==1){printf("No\n"),flag=0;break;}
		if(flag)printf("Yes\n");
	}
	return 0;
}