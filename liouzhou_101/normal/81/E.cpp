#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int INF=1000000000;

pair<int,int> operator + (pair<int,int> x,pair<int,int> y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

pair<int,int> operator - (pair<int,int> x,pair<int,int> y)
{
	return make_pair(x.first-y.first,x.second-y.second);
}

const int MaxN=100010;

int n;
int f[MaxN],s[MaxN];
vector<int> v[MaxN];

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&f[i],&s[i]);
		v[f[i]].push_back(i);
	}
}

int used[MaxN];

pair<int,int> F[MaxN][2];

pair<int,int> have_0,have_1,have;
vector<pair<int,int> > list_0,list_1,ans;

void solve_0(int x,int cut)
{
	used[x]=1;
	F[x][0]=F[x][1]=make_pair(0,0);
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
		if (*it!=cut)
		{
			solve_0(*it,cut);
			F[x][0]=F[x][0]+max(F[*it][0],F[*it][1]);
		}
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
		if (*it!=cut)
			F[x][1]=max(F[x][1],F[x][0]-max(F[*it][0],F[*it][1])+F[*it][0]+make_pair(1,s[x]!=s[*it]));
}

void solve_1(int x,int cut)
{
	used[x]=1;
	F[x][0]=F[x][1]=make_pair(0,0);
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
		if (*it!=cut)
		{
			solve_1(*it,cut);
			F[x][0]=F[x][0]+max(F[*it][0],F[*it][1]);
		}
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
		if (*it!=cut) if (*it!=f[cut])
			F[x][1]=max(F[x][1],F[x][0]-max(F[*it][0],F[*it][1])+F[*it][0]+make_pair(1,s[x]!=s[*it]));
	if (x==f[cut]) F[x][1]=make_pair(-INF,0);
}

void get(int x,int cut,int p,pair<int,int> &have_0,vector<pair<int,int> > &list_0,bool limit)
{
	int flag=(p==0);
	if (p==-1) if (F[x][0]>=F[x][1]) flag=1;
	if (flag)
	{
		for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
			if (*it!=cut)
				get(*it,cut,-1,have_0,list_0,limit);
	}
	else
	{
		for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
			if (*it!=cut&&(!limit||*it!=f[cut])) if (F[x][1]==F[x][0]-max(F[*it][0],F[*it][1])+F[*it][0]+make_pair(1,s[x]!=s[*it]))
			{
				get(*it,cut,0,have_0,list_0,limit);
				for (vector<int>::iterator pit=v[x].begin();pit!=v[x].end();++pit)
					if (pit!=it&&*pit!=cut)
						get(*pit,cut,-1,have_0,list_0,limit);
				list_0.push_back(make_pair(x,*it));
				have_0=have_0+make_pair(1,s[x]!=s[*it]);
				break;
			}
	}
}

void work()
{
	for (int i=1;i<=n;++i)
	{
		if (used[i]) continue;
		int x=i;
		for (;!used[x];x=f[x])
			used[x]=1;
		solve_0(x,x);
		list_0.clear();
		have_0=make_pair(0,0);
		get(x,x,-1,have_0,list_0,0);
		solve_1(x,x);
		list_1.clear();
		have_1=make_pair(0,0);
		get(x,x,0,have_1,list_1,1);
		have_1=have_1+make_pair(1,s[x]!=s[f[x]]);
		list_1.push_back(make_pair(x,f[x]));
		have=have+max(have_0,have_1);
		if (have_0>=have_1)
			for (int k=0;k<list_0.size();++k)
				ans.push_back(list_0[k]);
		else
			for (int k=0;k<list_1.size();++k)
				ans.push_back(list_1[k]);
	}
	cout<<have.first<<" "<<have.second<<endl;
	for (int i=0;i<ans.size();++i)
		printf("%d %d\n",ans[i].first,ans[i].second);
}

int main()
{
	init();
	work();
	return 0;
}