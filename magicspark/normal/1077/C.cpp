#include<bits/stdc++.h>
#define int long long
#pragma comment(linker,"/STACK:128000000,128000000")
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const long long inf2=0x3f3f3f3f3f3f3f3f;
int n;
int a[1111111];
int g[1111111];
vector<int> ans;
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),g[a[i]]++;
	long long sum=0;
	ans.clear();
	for(int i=1;i<=n;i++)sum+=a[i];
	for(int i=1;i<=n;i++){
		if((sum-a[i])%2==0){
			long long cur=(sum-a[i])/2;
			if(cur>1000005)continue;
			if(g[cur]>=1&&(a[i]!=cur||g[cur]>=2))ans.push_back(i); 
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
	return 0;
}
/*
5
2 1 2 4 3
*/