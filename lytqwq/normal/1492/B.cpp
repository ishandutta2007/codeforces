#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int T,n,p[N];
int maxn[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&p[i]);
			if(p[i]>p[maxn[i-1]]){
				maxn[i]=i;
			}
			else{
				maxn[i]=maxn[i-1];
			}
		}
		for(int i=n;i>=1;i=maxn[i]-1){
			for(int o=maxn[i];o<=i;o++){
				printf("%d ",p[o]);
			}
		}
		printf("\n");
	}
	return 0;
}