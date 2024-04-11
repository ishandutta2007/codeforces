#include<bits/stdc++.h>
using namespace std;
const int N=110;
int T,n,a[N],ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(i==1)ans=a[i];
			else ans&=a[i];
		}
		printf("%d\n",ans);
	}
}