#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T;
char s[2002][2002],t[2002][2002];
int mx[26],Mx[26],my[26],My[26];
main()
{
	scanf("%d\n",&T);
	for(;T--;)
	{
		int H,W;
		scanf("%d%d\n",&H,&W);
		for(int i=0;i<26;i++)
		{
			mx[i]=my[i]=114514;
			Mx[i]=My[i]=-114514;
		}
		for(int i=0;i<H;i++)
		{
			scanf("%s\n",s[i]);
			for(int j=0;j<W;j++)
			{
				t[i][j]='.';
				if(s[i][j]!='.')
				{
					int id=s[i][j]-'a';
					mx[id]=min(mx[id],i);
					my[id]=min(my[id],j);
					Mx[id]=max(Mx[id],i);
					My[id]=max(My[id],j);
				}
			}
			t[i][W]=0;
		}
		vector<pair<pair<int,int>,pair<int,int> > >ans;
		vector<int>tmp;
		bool out=0;
		for(int i=0;i<26;i++)
		{
			if(mx[i]>Mx[i]||my[i]>My[i])
			{
				tmp.push_back(i);
				continue;
			}
			if(mx[i]!=Mx[i]&&my[i]!=My[i])
			{
				out=1;
				break;
			}
			tmp.push_back(i);
			for(int u:tmp)
			{
				ans.push_back(make_pair(make_pair(mx[i],my[i]),make_pair(Mx[i],My[i])));
			}
			tmp.clear();
		}
		if(out)
		{
			puts("NO");
			continue;
		}
		for(int i=0;i<ans.size();i++)
		{
			int lx=ans[i].first.first,ly=ans[i].first.second,rx=ans[i].second.first,ry=ans[i].second.second;
			if(lx==rx)
			{
				for(int j=ly;j<=ry;j++)t[lx][j]=i+'a';
			}
			else
			{
				for(int j=lx;j<=rx;j++)t[j][ly]=i+'a';
			}
		}
		bool flag=1;
		for(int i=0;i<H;i++)for(int j=0;j<W;j++)flag&=s[i][j]==t[i][j];
		if(flag)
		{
			puts("YES");
			printf("%d\n",(int)ans.size());
			for(int i=0;i<ans.size();i++)
			{
				printf("%d %d %d %d\n",ans[i].first.first+1,ans[i].first.second+1,ans[i].second.first+1,ans[i].second.second+1);
			}
		}
		else
		{
			puts("NO");
		}
	}
}