#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,flg;
int A,B,C,D;
int a[maxn],b[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		vector<int>v[2];
		long long sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]),sum+=b[i];
			v[a[i]].push_back(b[i]);
		}
		sort(v[0].begin(),v[0].end()),sort(v[1].begin(),v[1].end());
		if(v[0].size()==v[1].size())
			printf("%lld\n",sum+sum-min(v[0][0],v[1][0]));
		else{
			long long ans=0;
			int k=min(v[0].size(),v[1].size());
			for(int i=(int)v[0].size()-k;i<v[0].size();i++)
				ans+=v[0][i];
			for(int i=(int)v[1].size()-k;i<v[1].size();i++)
				ans+=v[1][i];
			printf("%lld\n",sum+ans);
		}
	}
	return 0;
}