#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,x,y,cnt[1111],ansx[1111],ansy[1111],ct,pos;
bool used[1111];
vector<int> v;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		if (x>y) swap(x,y);
		if (y!=n)
		{
			printf("NO\n");
			return 0;
		}
		cnt[x]++;
	}
	for (int i=1;i<n;i++)
	{
		if (!cnt[i]) continue;
		v.clear();
		v.push_back(i);pos=i-1;
		while(pos>=1 && v.size()<cnt[i])
		{
			if (!cnt[pos] && !used[pos])
			{
				v.push_back(pos);
				used[pos]=1;
			}
			pos--;
		} 
		if (v.size()<cnt[i])
		{
			printf("NO\n");
			return 0;
		}
		if (v.size()==1)
		{
			ct++;
			ansx[ct]=n;ansy[ct]=i;
			continue;
		}
		ct++;
		ansx[ct]=n;ansy[ct]=v[1];
		for (int j=1;j<(int)v.size()-1;j++)
		{
			ct++;
			ansx[ct]=v[j];ansy[ct]=v[j+1];
		}
		ct++;
		ansx[ct]=v[(int)v.size()-1];ansy[ct]=v[0];
	}
	printf("YES\n");
	for (int i=1;i<n;i++)
	{
		printf("%d %d\n",ansx[i],ansy[i]);
	}
	return 0;
}