#include<bits/stdc++.h>
using namespace std;
const int N=59;
int a[N][N];
int main(){
	int T; cin>>T;
	while(T--){
		int n,m; cin>>n>>m;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
		int mc=100,mr=100; 
		for(int i=1;i<=n;i++){
			bool clear=1;
			for(int j=1;j<=m;j++) clear&=(!a[i][j]);
			mc+=clear;
		}
		for(int i=1;i<=m;i++){
			bool clear=1;
			for(int j=1;j<=n;j++) clear&=(!a[j][i]);
			mr+=clear;
		}
		int ans=min(mc,mr);
		if(ans%2) puts("Ashish");
		else puts("Vivek");
	}
	return 0;
}