#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>
#define ll long long 
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
template <typename T> inline void chmin(T &x,const T &b) {x=(x<b?x:b);}
template <typename T> inline void chmax(T &x,const T &b) {x=(x>b?x:b);}
using namespace std;
int n,m;
vector<vector<int> > a;
vector<int> diff[250005];
int b[250005];
vector<int> colors[250005];
vector<vector<int> > gridOfColors[250005];
vector<int> needChange[250005];

void print()
{
	cout<<"Yes"<<endl;
	for(int i=0;i<m;i++)
	{
		printf("%d ",a[0][i]);
	}
	puts("");
	exit(0);
}

int main()
{
	cin>>n>>m;
	a.resize(n,vector<int>(m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]!=a[0][j]) diff[i].push_back(j);
		}
	}
	int flag=true;
	for(int i=0;i<n;i++)
	{
		flag&=(diff[i].size()<=2);
	}
	if(flag)
	{
		print();
	}
	for(int i=0;i<n;i++)
	{
		if(diff[i].size()>4)
		{
			puts("No");
			exit(0);
		}
	}
	int s=0;
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<n;i++)
		{
			colors[j].push_back(a[i][j]);
		}
		sort(colors[j].begin(),colors[j].end());
		colors[j].erase(unique(colors[j].begin(),colors[j].end()),colors[j].end());
		s+=colors[j].size()-1;
		gridOfColors[j].resize(colors[j].size());
		for(int i=0;i<n;i++)
		{
			int t=lower_bound(all(colors[j]),a[i][j])-colors[j].begin();
			gridOfColors[j][t].push_back(i);
		}
	}
	if(s>2*n)
	{
		puts("No");
		return 0;
	}
	for(int j=0;j<m;j++)
	{
		for(int c=0;c<(int)colors[j].size();c++)
		{
			for(int i=1;i<n;i++)
			{
				b[i]=diff[i].size();
			}
			for(auto p:gridOfColors[j][c]) b[p]--;
			for(int i=1;i<n;i++)
			{
				if(a[i][j]==a[0][j]) b[i]++;
			}
			vector<int> vpos;
			int cnt=0;
			for(int i=1;i<n;i++)
			{
				if(b[i]>3) goto Label;
			}
			flag=true;
			for(int i=1;i<n;i++)
			{
				flag&=(b[i]<=2);
			}
			if(flag)
			{
				a[0][j]=colors[j][c];
				print();
			}
			for(int i=1;i<n;i++)
			{
				if(b[i]==3 || b[i]==2)
				{
					cnt++;
					for(auto pos:diff[i])
					{
						needChange[pos].push_back(b[i]==2?-1:a[i][pos]);
						vpos.push_back(pos);
					}
				}
			}
			for(auto pos:vpos)
			{
				if(pos==j) continue;
				if((int)needChange[pos].size()!=cnt) continue;
				int tov=-1;
				flag=true;
				for(auto c:needChange[pos])
				{
					if(tov!=-1 && c!=-1 && tov!=c)
					{
						flag=false;
						break;
					}
					tov=max(tov,c);
				}
				if(flag==true)
				{
					a[0][j]=colors[j][c];
					a[0][pos]=tov;
					print();
				}
			}
			Label:
			for(auto p:vpos) needChange[p].clear();
			for(int i=1;i<n;i++)
			{
				b[i]=0;
			}
		}
	}
	puts("No");
	return 0;
}