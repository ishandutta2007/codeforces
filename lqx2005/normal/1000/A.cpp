#include<bits/stdc++.h>
using namespace std;
int n;
string x;
map<string,int> s,t;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x,s[x]++;
	for(int i=1;i<=n;i++) cin>>x,t[x]++;
	int ans=0;
	int sum=s["M"]+s["S"]+s["L"];
	sum-=min(t["M"],s["M"]);
	sum-=min(t["S"],s["S"]);
	sum-=min(t["L"],s["L"]);
	ans+=sum;
	sum=s["XS"]+s["XL"];
	sum-=min(t["XS"],s["XS"]);
	sum-=min(t["XL"],s["XL"]);
	ans+=sum;
	sum=s["XXS"]+s["XXL"];
	sum-=min(t["XXS"],s["XXS"]);
	sum-=min(t["XXL"],s["XXL"]);
	ans+=sum;
	sum=s["XXXS"]+s["XXXL"];
	sum-=min(t["XXXS"],s["XXXS"]);
	sum-=min(t["XXXL"],s["XXXL"]);
	ans+=sum;
	printf("%d\n",ans);
	return 0;
}