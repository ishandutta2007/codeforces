#include<bits/stdc++.h>
using namespace std;
int const N=233;
int n,k,pre[N];
pair<int,int>ans[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1,a;i<=n*k;i++)
		if(cin>>a,!ans[a].first&&pre[a]){
			ans[a]={pre[a],i};
			for(int p=a-(a-1)%(k-1)-1,j=p+1;j<p+k;j++)
				pre[j]=0;
		}else pre[a]=i;
	for(int i=1;i<=n;i++)
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
}