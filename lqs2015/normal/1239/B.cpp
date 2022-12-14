#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,pre[333333],mns[333333],mnp[333333],mn,val,al,ar,ans,pre1[333333],pre2[333333],pre3[333333],suf1[333333],r1,r2,c1,c2,p1,p2;
char s[333333];
set<pair<int,int> > s1,s2;
pair<int,int> pd;
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=1;i<=n;i++)
	{
		if (s[i-1]=='(') pre[i]=pre[i-1]+1;
		else pre[i]=pre[i-1]-1;
	}
	mn=1e9;
	for (int i=1;i<=n;i++)
	{
		mn=min(mn,pre[i]);
	}
	if (pre[n]!=0)
	{
		printf("0\n");
		printf("1 1\n");
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		if (pre[i]==mn) ans++;
	}
	mns[n+1]=mnp[0]=1e9;
	for (int i=n;i>=1;i--) mns[i]=min(mns[i+1],pre[i]);
	for (int i=1;i<=n;i++) mnp[i]=min(mnp[i-1],pre[i]);
	al=ar=1;
	for (int i=mn-2;i<=mn+2;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (pre[j]==i) pre1[j]=pre1[j-1]+1;
			else pre1[j]=pre1[j-1];
			if (pre[j]==i-2) pre2[j]=pre2[j-1]+1;
			else pre2[j]=pre2[j-1];
			if (pre[j]==i+2) pre3[j]=pre3[j-1]+1;
			else pre3[j]=pre3[j-1];
		}
		for (int j=n;j>=1;j--)
		{
			if (pre[j]==i) suf1[j]=suf1[j+1]+1;
			else suf1[j]=suf1[j+1];
		}
		s1.clear();s2.clear();r1=r2=0;
		for (int j=1;j<=n;j++)
		{
			if (r1<j) 
			{
				r1++;
				while(r1<=n && pre[r1]>=i+2) 
				{
					if (s[r1-1]==')')
					{
						if (mns[r1]==i) s1.insert(make_pair(suf1[r1]+pre3[r1-1],r1));
						else if (mns[r1]>i) s1.insert(make_pair(pre3[r1-1],r1));
					}
					r1++;
				}
				if (r1<=n && s[r1-1]==')')
				{
					if (mns[r1]==i) s1.insert(make_pair(suf1[r1]+pre3[r1-1],r1));
					else if (mns[r1]>i) s1.insert(make_pair(pre3[r1-1],r1));
				}
			}
			if (r2<j) 
			{
				r2++;	
				while(r2<=n && pre[r2]>=i-2)
				{
					if (s[r2-1]=='(')
					{
						if (mns[r2]==i) s2.insert(make_pair(suf1[r2]+pre2[r2-1],r2));
						else if (mns[r2]>i) s2.insert(make_pair(pre2[r2-1],r2));
					}
					r2++;
				}
				if (r2<=n && s[r2-1]=='(')
				{
					if (mns[r2]==i) s2.insert(make_pair(suf1[r2]+pre2[r2-1],r2));
					else if (mns[r2]>i) s2.insert(make_pair(pre2[r2-1],r2));
				}
			}
			if (s[j-1]=='(') 
			{
				if (!s1.empty())
				{
					pd=*s1.rbegin();
					val=pd.first-pre3[j-1];
					if (mnp[j-1]==i) val+=pre1[j-1];
					else if (mnp[j-1]<i) val=-1e9;
					if (val>=ans) 
					{
						ans=val;
						al=j;ar=pd.second;
					}
				}
				if (s2.find(make_pair(suf1[j]+pre2[j-1],j))!=s2.end()) s2.erase(s2.find(make_pair(suf1[j]+pre2[j-1],j)));
				if (s2.find(make_pair(pre2[j-1],j))!=s2.end()) s2.erase(s2.find(make_pair(pre2[j-1],j)));
			}
			else
			{
				if (!s2.empty())
				{
					pd=*s2.rbegin();
					val=pd.first-pre2[j-1];
					if (mnp[j-1]==i) val+=pre1[j-1];
					else if (mnp[j-1]<i) val=-1e9;
					if (val>=ans) 
					{
						ans=val;
						al=j;ar=pd.second;
					}
				}
				if (s1.find(make_pair(suf1[j]+pre3[j-1],j))!=s1.end()) s1.erase(s1.find(make_pair(suf1[j]+pre3[j-1],j)));
				if (s1.find(make_pair(pre3[j-1],j))!=s1.end()) s1.erase(s1.find(make_pair(pre3[j-1],j)));
			}
		}
	}
	printf("%d\n",ans);
	printf("%d %d\n",al,ar);
	return Accepted;
}