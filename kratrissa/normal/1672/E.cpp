#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,S,ans;
int main(){
	scanf("%d",&n);
	int l=2*n-1,r=2001*n-1;
	while(l<=r){
		int mid=l+r>>1,res;
		printf("? %d\n",mid),fflush(stdout),scanf("%d",&res);
		if(res!=1)l=mid+1;
		else r=mid-1;
	}
	S=l+1,ans=l;
	for(int w=2;w<=n;w++){
		int t=(S-2)/w,res;
		printf("? %d\n",t),fflush(stdout),scanf("%d",&res);
		if(res==w)ans=min(ans,w*t);
		if(res==0)break;
	}
	printf("! %d\n",ans),fflush(stdout);
	return 0;
}