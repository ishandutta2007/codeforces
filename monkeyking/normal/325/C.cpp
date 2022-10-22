#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
const int MAX=3.14e8;
using namespace std;
bool die[100005];
bool cycle[100005];
int visit[100005];
int n,m;
int dpmax[100005];
int dist[100005];
bool legal[100005];

class Spliting
{
	public:
	vector <int> vec;
	int diamonds;
	int unique_id;
};
class TLE
{
	public:
	map <int,int> monster;
	int size;
	int diamonds;
	int destination;
	int unique_id_for_the_fucking_set;
	void print()
	{
		cout<<""<<unique_id_for_the_fucking_set+1<<"    "; 
		cout<<""<<size<<"   ";
		cout<<""<<diamonds<<"   ";
		cout<<""<<this->destination+1<<"   "; 
		cout<<endl;
	}
}method[100005];
vector <Spliting> vec[100005];
vector <TLE*> monkey[100005];
//TLE:: bool operator < (const TLE *b)const
//{
	
//}
struct compare
{
	bool operator () (TLE *a, TLE *b)
	{
		if(a->size!=b->size)
		{
			return a->size<b->size;
		}
		if(a->diamonds!=b->diamonds) return a->diamonds<b->diamonds;
		return a->unique_id_for_the_fucking_set<b->unique_id_for_the_fucking_set;
//		return a->diamonds<b->diamonds;
	}
};
set <TLE*,compare> squ;
//priority_queue <TLE*,vector<TLE*>,compare> que;

bool findc(int x)
{
	bool cyc=false;
	visit[x]=1;
	for(auto &type:vec[x])
	{
		if(!legal[type.unique_id]) continue;
		for(auto &u:type.vec)
		{
			if(cycle[u])
			{
				cyc=true;
				continue;
			}
			if(visit[u]==1)
			{
				cyc=true;
				continue;
			}
			if(visit[u]==2) continue;
			if(visit[u]==0)
			{
				bool t=findc(u);
				if(t==true)
				{
					cyc=true;
				}
			}
		}
	}
	cycle[x]|=cyc;
	visit[x]=2;
	return cyc;
}

int dfsmax(int x)
{
	if(visit[x]) return dpmax[x];
	visit[x]=true;
	dpmax[x]=0;
	int diamonds=0;
	for(auto &type:vec[x])
	{
		diamonds=type.diamonds;
		if(!legal[type.unique_id]) continue;
		for(auto &u:type.vec)
		{
			diamonds+=dfsmax(u);
			diamonds=min(MAX,diamonds);
		}
		dpmax[x]=max(dpmax[x],diamonds);
	}
	return dpmax[x];
}

void unlock(int x)
{
//	cout<<x+1<<endl;
	for(auto it:monkey[x])
	{
		squ.erase(it);
		it->diamonds+=min((ll)MAX,1LL*it->monster[x]*dist[x]);
		if(it->diamonds>MAX) it->diamonds=MAX;
//		if(it->unique_id_for_the_fucking_set==2) cout<<"F88K"<<' '<<x<<endl;
		it->monster.erase(x);
		it->size--;
		squ.insert(it);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int type,num,item;
	Spliting x;
	for(int i=0;i<n;i++)
	{
		cin>>type>>num;
		type--;
		x.vec.clear();
		x.diamonds=0;
		x.unique_id=i;
		for(int j=0;j<num;j++)
		{
			cin>>item;
			if(item==-1)
			{
				x.diamonds++;
				method[i].diamonds++;
			}
			else
			{
				item--;
				x.vec.push_back(item);
				method[i].monster[item]++;
//				monkey[item].push_back(&method[i]);
			}
		}
		for(auto x:method[i].monster)
		{
			monkey[x.first].push_back(&method[i]);
		}
		method[i].unique_id_for_the_fucking_set=i;
		method[i].size=method[i].monster.size();
		method[i].destination=type;
		vec[type].push_back(x);
	}
	// 
	memset(visit,false,sizeof(visit));
	for(int i=0;i<n;i++)
	{
		squ.insert(&method[i]);
	}
	while(squ.size())
	{
		TLE *x=*squ.begin();
		squ.erase(squ.begin());
//		x->print();
		if(x->size!=0) break;
		legal[x->unique_id_for_the_fucking_set]=true;
		if(visit[x->destination]) continue;
		visit[x->destination]=true;
		dist[x->destination]=x->diamonds;
		unlock(x->destination);
	}
	for(int i=0;i<m;i++)
	{
		if(!visit[i]) die[i]=true;
	}
	// 
	memset(visit,false,sizeof(visit));
	for(int i=0;i<m;i++)
	{
		if(visit[i]==0)
		{
			findc(i);
		}
	}
	// 
	memset(visit,false,sizeof(visit));
	for(int i=0;i<m;i++)
	{
		if(!die[i]) dfsmax(i);
	}
	for(int i=0;i<m;i++)
	{
		if(die[i]) cout<<-1<<' '<<-1<<endl;
		else
		{
			cout<<dist[i]<<' ';
			if(cycle[i]) cout<<-2<<endl;
			else cout<<dpmax[i]<<endl;
		}
	}
	return 0;
}