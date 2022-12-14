#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k,ans,i,cur;
pair<int,int> a[11111];
char s[11111];
string sk,res;
bool cmp(pair<int,int> j,pair<int,int> k)
{
	if (abs(j.first-i)!=abs(k.first-i)) return abs(j.first-i)<abs(k.first-i);
	if (j.first<i && k.first>i) return 0;
	if (j.first>i && k.first<i) return 1;
	if (j.first<i) return j.second>k.second;
	return j.second<k.second;
}
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	ans=1e9;
	for (i=0;i<=9;i++)
	{
		for (int j=0;j<n;j++) a[j]=make_pair(s[j]-'0',j);
		sort(a,a+n,cmp);
		sk="";
		cur=0;
		for (int j=0;j<n;j++) sk+=s[j];
		for (int j=0;j<k;j++)
		{
			cur+=abs(a[j].first-i);
			sk[a[j].second]='0'+i;
		}
		if (cur<ans || (cur==ans && (res=="" || sk<res))) 
		{
			ans=cur;
			res=sk;
		}
	}
	printf("%d\n",ans);
	cout<<res<<endl;
	return 0;
}