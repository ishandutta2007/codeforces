#include<bits/stdc++.h>
using namespace std;
const int N=400010;
int T,a,b;
int ans[N],sum,q[N],coo;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		int n=a+b;
		sum=0;coo=0;
		ans[0]=-1;
		if(n%2==0){
			int ch=n/2;
			for(int awi=0;awi<=min(ch,a);awi++){
				int ali=ch-awi;
				if(ali>b)continue;
				int bwi=b-ali;
				if(bwi<0)continue;
				int bli=ch-bwi;
				if(bli>a)continue;
				ans[++sum]=ali+bli;
			}
			sort(ans+1,ans+sum+1);
			for(int i=1;i<=sum;i++){
				if(ans[i]!=ans[i-1]){
					q[++coo]=ans[i];
				}
			}
			printf("%d\n",coo);
			for(int i=1;i<=coo;i++)printf("%d ",q[i]);
			printf("\n");
		}
		else{
			int ch=n/2+1;
			for(int awi=0;awi<=min(ch,a);awi++){
				int ali=ch-awi;
				if(ali>b)continue;
				int bwi=b-ali;
				if(bwi<0)continue;
				int bli=ch-1-bwi;
				if(bli>a)continue;
				ans[++sum]=ali+bli;
			}
			ch=n/2;
			for(int awi=0;awi<=min(ch,a);awi++){
				int ali=ch-awi;
				if(ali>b)continue;
				int bwi=b-ali;
				if(bwi<0)continue;
				int bli=ch+1-bwi;
				if(bli>a)continue;
				ans[++sum]=ali+bli;
			}
			sort(ans+1,ans+sum+1);
			for(int i=1;i<=sum;i++){
				if(ans[i]!=ans[i-1]){
					q[++coo]=ans[i];
				}
			}
			printf("%d\n",coo);
			for(int i=1;i<=coo;i++)printf("%d ",q[i]);
			printf("\n");
			
		}
	}
}