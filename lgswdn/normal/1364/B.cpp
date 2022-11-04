#include<bits/stdc++.h>
using namespace std;
int a[100009];
int main(){
	int T; cin>>T;
	while(T--){
		int n; scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int cnt=0;
		cnt++;
		for(int i=2;i<n;i++){
			if((a[i]-a[i-1]>0)!=(a[i+1]-a[i]>0)) cnt++;
		}
		cnt++; printf("%d\n",cnt);
		printf("%d ",a[1]);
		for(int i=2;i<n;i++){
			if((a[i]-a[i-1]>0)!=(a[i+1]-a[i]>0)) printf("%d ",a[i]);
		}
		printf("%d\n",a[n]);
	}
	return 0;
}