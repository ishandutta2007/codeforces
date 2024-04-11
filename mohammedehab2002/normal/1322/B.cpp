#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int f(int x)
{
    int r=v.size(),ans=0;
    for (int l=0;l<v.size();l++)
    {
    	r=max(r,l);
    	while (r>l && v[l]+v[r-1]>=x)
    	r--;
    	ans^=(r-l)%2;
    }
    return ans;
}
int main()
{
    int n,ans=0,tmp=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
    	int a;
    	scanf("%d",&a);
    	v.push_back(a);
    	tmp^=2*a;
    }
    sort(v.begin(),v.end());
    for (int i=(1<<28);i;i/=2)
    {
    	vector<int> v1,v2;
    	for (int j:v)
    	{
    		if (j<2*i)
    		v1.push_back(j);
    		else
    		v2.push_back(j-2*i);
    	}
    	v.clear();
    	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v));
    	int cnt=(f(4*i)^f(3*i)^f(2*i)^f(i));
    	ans+=i*cnt;
    }
    printf("%d",(ans^tmp));
}