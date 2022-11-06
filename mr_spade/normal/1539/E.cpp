#include<bits/stdc++.h>
using namespace std;
#define endl lend
const int N=1e6+5;
int n,m;
int k[N];
vector<int> endl[N],endr[N];
int al[N],bl[N],ar[N],br[N];
set<pair<int,int>> S;
set<int> Sa,Sb;
map<pair<int,int>,pair<int,int>> M;
inline void print(int x,int y)
{
	if(x>1)
	{
		if(M.find(make_pair(x,y))!=M.end())
			print(M[make_pair(x,y)].first,M[make_pair(x,y)].second);
		else
			print(x-1,y);
	}
	if(y>2*n)
		cout<<"1 ";
	else
		cout<<"0 ";
	return;
} 
signed main()
{
	register int i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>k[i]>>al[i]>>bl[i]>>ar[i]>>br[i];
	S.insert(make_pair(0,0));
	for(i=1;i<=n;i++)
	{
		S.insert(make_pair(k[i],i));
		while(!S.empty()&&S.begin()->first<al[i])
			endl[i].push_back(S.begin()->second),S.erase(S.begin());
		while(!S.empty()&&S.rbegin()->first>bl[i])
			endl[i].push_back(S.rbegin()->second),S.erase(*S.rbegin());
	}
	while(!S.empty())
		S.erase(S.begin());
	S.insert(make_pair(0,0));
	for(i=1;i<=n;i++)
	{
		S.insert(make_pair(k[i],i));
		while(!S.empty()&&S.begin()->first<ar[i])
			endr[i].push_back(S.begin()->second),S.erase(S.begin());
		while(!S.empty()&&S.rbegin()->first>br[i])
			endr[i].push_back(S.rbegin()->second),S.erase(*S.rbegin());
	}
	while(!S.empty())
		S.erase(S.begin());
	Sa.insert(0);Sb.insert(0);
	for(i=1;i<=n;i++)
	{
		for(int x:endl[i])
			if(x<i)
			{
				if(Sb.find(x)!=Sb.end())
					Sb.erase(x);
			}
			else
				Sa.clear();
		for(int x:endr[i])
			if(x<i)
			{
				if(Sa.find(x)!=Sa.end())
					Sa.erase(x);
			}
			else
				Sb.clear();
		if(i<n)
		{
			if(!Sa.empty()&&!Sb.empty())
			{
				M[make_pair(i+1,3*n+i)]=make_pair(i,*Sa.begin());
				M[make_pair(i+1,i)]=make_pair(i,3*n+*Sb.begin());
				Sb.insert(i);
				Sa.insert(i);
			}
			else if(!Sb.empty())
			{
				M[make_pair(i+1,i)]=make_pair(i,3*n+*Sb.begin());
				Sa.insert(i);
			}
			else if(!Sa.empty())
			{
				M[make_pair(i+1,3*n+i)]=make_pair(i,*Sa.begin());
				Sb.insert(i);
			}
		}
	}
	if(!Sa.empty())
		puts("Yes"),print(n,*Sa.begin()),puts("");
	else if(!Sb.empty())
		puts("Yes"),print(n,3*n+*Sb.begin()),puts("");
	else
		puts("No");
	return 0;
}