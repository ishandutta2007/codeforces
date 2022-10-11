#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int> > ans;
int z[100005],cum[100005];
int main()
{
	string s;
	cin >> s;
	z[0]=s.size();
	int l=0,r=0;
	for (int i=1;i<s.size();i++)
	{
		if (i>r)
		{
			l=r=i;
			while (r<s.size() && s[r]==s[r-l])
			r++;
			z[i]=r-l;
			r--;
		}
		else
		{
			int k=i-l;
			if (z[k]<r-i+1)
			z[i]=z[k];
			else
			{
				l=i;
				while (r<s.size() && s[r]==s[r-l])
				r++;
				z[i]=r-l;
				r--;
			}
		}
	}
	for (int i=0;i<s.size();i++)
	cum[z[i]]++;
	for (int i=s.size();i>=0;i--)
	cum[i]+=cum[i+1];
	for (int i=s.size()-1;i>=0;i--)
	{
		if (z[i]+i==s.size())
		ans.push_back({s.size()-i,cum[s.size()-i]});
	}
	printf("%d\n",ans.size());
	for (auto i:ans)
	printf("%d %d\n",i.first,i.second);
}