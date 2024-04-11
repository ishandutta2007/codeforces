#include <bits/stdc++.h>

using namespace std;

vector<int> adj[400005], adjt[400005];
int ans[400005];
int tid[400005];
int val[400005];
vector<int> query[400005];
int childs[400005][26], childt[400005][26];
int fa[400005];
int curtime=0;
int st[400005], en[400005];
int fail[400005][26];
string gchar;
int nodecnt=0;
int bit[400005];
int n, m;

int getchild(int node, int cha)
{
	if(childt[node][cha])
	{
		return childt[node][cha];
	}
	else
	{
		nodecnt++;
		childt[node][cha]=nodecnt;
		return nodecnt;
	}
}

int stradd()
{
	int curnode=0;
	for(int i=0; i<gchar.size(); i++)
	{
		curnode=getchild(curnode, gchar[i]-'a');
	}
	return curnode;
}

void bfs()
{
	queue<int> q;
	q.push(0);
	while(q.size())
	{
		int node=q.front();
		q.pop();
		for(int i=0; i<26; i++)
		{
			fail[node][i]=fail[fa[node]][i];
			int lel=childt[node][i];
			if(lel)
			{
				fa[lel]=fail[node][i];
				fail[node][i]=lel;
				q.push(lel);
			}
		}
	}
	for(int i=1; i<=nodecnt; i++)
	{
		adjt[fa[i]].push_back(i);
	}
}

void add(int pos, int val)
{
	while(pos<400005)
	{
		bit[pos]+=val;
		pos+=pos&-pos;
	}
}

int get(int pos)
{
	int ret=0;
	while(pos>0)
	{
		ret+=bit[pos];
		pos-=pos&-pos;
	}
	return ret;
}

void dfs(int node)
{
	curtime++;
	st[node]=curtime;
	for(auto i:adjt[node])
	{
		dfs(i);
	}
	en[node]=curtime;
}

int rget(int l, int r)
{
	return get(r)-get(l-1);
}

void solve(int node, int cur)
{
	add(st[cur], 1);
	// cout<<bit[10]<<endl;
	for(auto i:query[node])
	{
		// cout<<st[tid[i]]<<" "<<en[tid[i]]<<endl;
		ans[i]=rget(st[tid[i]], en[tid[i]]);
	}
	for(auto i:adj[node])
	{
		solve(i, fail[cur][val[i]]);
	}
	add(st[cur], -1);
}

signed main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			cin>>gchar;
			gchar[0]-='a';
			adj[0].push_back(i);
		}
		else
		{
			int fa;
			cin>>fa>>gchar;
			gchar[0]-='a';
			adj[fa].push_back(i);
		}
		val[i]=gchar[0];
		// cout<<val[i]<<endl;
	}
	cin>>m;
	for(int i=1; i<=m; i++)
	{
		int id;
		cin>>id>>gchar;
		tid[i]=stradd();
		query[id].push_back(i);
	}
	bfs();
	dfs(0);
	solve(0, 0);
	// for(int i=1; i<=nodecnt; i++)
	// {
	// 	for(int j=0; j<26; j++)
	// 	{
	// 		cout<<fail[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// for(int i=1; i<=10; i++)
	// {
	//    cout<<fa[i]<<endl;
	// }
	// for(int i=0; i<5; i++)
	// {
	//    cout<<fail[i][0]<<endl;
	// }
	// for(int i=5; i<10; i++)
	// {
	//    cout<<fail[i][1]<<endl;
	// }
	for(int i=1; i<=m; i++)
	{
		// cout<<st[tid[i]]<<" "<<en[tid[i]]<<endl;
		cout<<ans[i]<<"\n";
	}
}