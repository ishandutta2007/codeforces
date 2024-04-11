#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[4];
int b[4];
const int N=1001001;
int ans[N];
int main(){
	ios::sync_with_stdio(false);
	int n=0;
	for(int i=0;i<4;i++){
		cin>>a[i];
		n+=a[i];
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)b[j]=a[j];
		ans[0]=i;
		if(--b[i]<0){
			goto no;
		}
		// cerr<<i<<endl;
		for(int j=1;j<n;j++){
			int x=ans[j-1];
			ans[j]=b[x^1]>0?x^1:x-((x^1)-x);
			// cerr<<j<<" "<<ans[j]<<endl;
			if(ans[j]<0||ans[j]>=4||(--b[ans[j]])<0){
				goto no;
			}
		}
		puts("YES");
		for(int i=0;i<n;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
		exit(0);
		no:;
	}
	puts("NO");
	return 0;
}