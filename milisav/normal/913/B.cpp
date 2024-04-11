#include <bits/stdc++.h>
using namespace std;
vector<int> c[2000];
int n;
int p[2000];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&p[i]);
		p[i]--;
		c[p[i]].push_back(i);
	}
	bool s=true;
	int d=0;
	for(int i=0;i<n;i++)
	{
		d=0;
		if(c[i].size()>0)
		{
			for(int j=0;j<c[i].size();j++) if(c[c[i][j]].size()==0) d++;
			if(d<3) s=false; 
		}
	}
	if(s) printf("Yes");
	else printf("No");
	return 0;
}