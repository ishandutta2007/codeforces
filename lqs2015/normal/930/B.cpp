#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
char s[5555];
bool used[5555];
int n,cnt[28],mx,cur;
double ans;
vector<int> v;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<n;i++)
	{
		if (!used[i])
		{
			v.clear();
			for (int j=i;j<=n;j++)
			{
				if (s[j]==s[i]) 
				{
					used[j]=1;
					v.push_back(j); 
				}
			}
			mx=0;
			for (int j=1;j<n;j++)
			{
				memset(cnt,0,sizeof(cnt));
				for (int k=0;k<v.size();k++)
				{
					cnt[s[(v[k]+j)%n]-'a']++;
				}
				cur=0;
				for (int k=0;k<26;k++)
				{
					if (cnt[k]==1) cur++;
				}
				if (cur>mx) mx=cur;
			}
			ans=ans+(double)mx;
		}
	}
	printf("%.9lf\n",ans/(double)n);
	return 0;
}