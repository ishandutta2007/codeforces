#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005

int color[mn*10];
int nxt[mn*10];
int prv[mn*10];
bool outed[mn*10];
string S;
int n;
bool able=1;
queue <int> Q;

void operate()
{
	able=0;
//	cerr<<Q.size()<<"\n";
	set <int> bd;
	
	bd.empty();
	if (Q.empty()) return;
	int i;
	while (!Q.empty())
	{
		i=Q.front();
		Q.pop();
		if (nxt[i]==i) nxt[prv[i]]=prv[i];
		else nxt[prv[i]]=nxt[i];
		if (prv[i]==i) prv[nxt[i]]=nxt[i];
		else prv[nxt[i]]=prv[i];
		outed[i]=1;
		bd.insert(nxt[i]);
		bd.insert(prv[i]);
	}
	
	for (int ptu: bd) if (!outed[ptu]) if (color[ptu]!=color[nxt[ptu]] || color[ptu]!=color[prv[ptu]]) 
	{
		Q.push(ptu);
//		cerr<<ptu<<"\n";
	}
	able=1;
}

main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	cin>>S;
	n=S.size();
	for (int i=1; i<=n; i++)
	{
		color[i]=S[i-1]-96;
		nxt[i]=min(n, i+1);
		prv[i]=max((int)1, i-1);
		outed[i]=0;
	}
	
	for (int i=1; i<=n; i++) if (color[i]!=color[nxt[i]] || color[i]!=color[prv[i]]) Q.push(i);
	
	int ans=-1;
	while (able) 
	{
		operate();
		ans++;
//		cerr<<"\n";
	}
	
	cout<<ans;
	
	
}