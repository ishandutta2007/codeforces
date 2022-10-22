#include<bits/stdc++.h>
using namespace std;
const int N=300010;
int T,n,sum[N];
char a[N],b[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",a+1);
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+(a[i]=='1');
		}
		scanf("%s",b+1);
		int res=0,ok=1;
		for(int i=n;i>=1;i--){
			if(((a[i]=='1')^res)!=(b[i]=='1')){
				if((i%2==0)&&(sum[i]==i/2))res^=1;
				else ok=0;
			}
		}
		if(ok){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}