#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+10;
int n;
int a[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		int l=1,r=n,x;bool flag=0;
		while((x=r-l+1)>=3){
			if(a[l]==x) ++l;
			else if(a[r]==x) --r;
			else{
				flag=1;
				for(int i=l;i<=r;++i){
					if(a[i]==x){
						x=i;break;
					}
				}
				printf("YES\n%d %d %d\n",l,x,r);
				break;
			} 
		}
		if(!flag) printf("NO\n");
	}
	return 0;
}