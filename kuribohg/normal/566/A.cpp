#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
#include<vector>
#include<utility>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int MAXN=800010;
int n;
int ch[MAXN][26],tot=1;
vector<int> id1[MAXN];
vector<int> id2[MAXN];
char str[MAXN];
LL ans;
inline void Insert(char s[],vector<int> id[],int d)
{
	int n=strlen(s),x=1;
	for(int i=0;i<n;i++)
	{
		if(!ch[x][s[i]-'a']) ch[x][s[i]-'a']=++tot;
		x=ch[x][s[i]-'a'];
	}
	id[x].push_back(d);
}
PII operator+(const PII &p,const PII &q)
{
	return make_pair(p.first+q.first,p.second+q.second);
}
stack<int> A,B;
vector<PII> Ans;
PII DFS(int x,int dep)
{
	PII o;
	o.first=id1[x].size();
	for(int i=0;i<o.first;i++)
		A.push(id1[x][i]);
	o.second=id2[x].size();
	for(int i=0;i<o.second;i++)
		B.push(id2[x][i]);
	for(int i=0;i<26;i++)
		if(ch[x][i]) o=o+DFS(ch[x][i],dep+1);
	int p=min(o.first,o.second);
	ans+=(LL)p*(LL)dep;
	for(int i=1;i<=p;i++)
	{
		Ans.push_back(make_pair(A.top(),B.top()));
		A.pop(),B.pop();
	}
	o.first-=p,o.second-=p;
	return o;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%s",str),Insert(str,id1,i);
	for(int i=1;i<=n;i++) scanf("%s",str),Insert(str,id2,i);
	DFS(1,0);
	printf("%d\n",ans);
	for(int i=0;i<Ans.size();i++)
		printf("%d %d\n",Ans[i].first,Ans[i].second);
	return 0;
}