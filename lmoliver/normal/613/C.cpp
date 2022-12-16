#include<bits/stdc++.h>
using namespace std;
const int N=30;
int a[N];
int main(){
	int n;
	scanf("%d",&n);
	int sum=0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	int ans=0,id=0;
	for(int i=1;i<=sum;i++){
		if(sum%i!=0)continue;
		int c=sum/i%2;
		int tans=i*(2-sum/i%2);
		for(int j=0;j<n;j++){
			if(a[j]%i!=0||(a[j]/i%2!=0&&--c<0)){
				goto no;
			}
		}
		if(tans>ans){
			ans=tans;
			id=i;
		}
		no:;
	}
	printf("%d\n",ans);
	if(id==0){
		for(int i=0;i<n;i++){
			while(a[i]--)printf("%c",'a'+i);
		}
	}else{
		for(int i=0;i<id;i++){
			for(int j=0;j<n;j++){
				for(int _=0;_<a[j]/id/2;_++)printf("%c",'a'+j);
			}
			for(int j=0;j<n;j++){
				if(a[j]/id%2!=0)printf("%c",'a'+j);
			}
			for(int j=n-1;j>=0;j--){
				for(int _=0;_<a[j]/id/2;_++)printf("%c",'a'+j);
			}
		}
	}
	printf("\n");
	return 0;
}