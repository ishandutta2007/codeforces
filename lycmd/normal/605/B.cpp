#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,m,cur=1;
pair<int,int>ans[N];
array<int,3>a[N];
set<pair<int,int> >edge;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i][0]>>a[i][1],a[i][1]*=-1,a[i][2]=i;
	sort(a+1,a+1+m);
	for(int i=1;i<=m;i++)
		if(a[i][1]){
			cur++,ans[a[i][2]]={cur,cur-1};
			if(edge.size()<m)
				for(int j=1;j<cur-1;j++)
					edge.insert({j,cur});
		}else{
			if(edge.empty())
				cout<<"-1\n",exit(0);
			ans[a[i][2]]=*edge.begin();
			edge.erase(ans[a[i][2]]);
		}
	for(int i=1;i<=m;i++)
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
}