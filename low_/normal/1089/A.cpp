#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

vector <pii> ans[255][255];
int boost[255][255];
vector <pii> sets;

pii AB()
{
	int a=0, b=0;
	for (int i=1; i<sets.size(); i++) a+=sets[i].XX, b+=sets[i].YY;
	return {a, b};
}

void flood()
{
	for (int i=0; i<205; i++) for (int j=0; j<205; j++) if (boost[i][j]>0)
	{
		int k=1;
		while (1)
		{
			if (i+k>200 || j+k>200) break;
			if (boost[i+k][j+k]>0) 
			{
				k++;
				continue;
			}
//			if (i+k==67 && j+k==74)
//			{
//				cerr<<i<<" "<<j<<" "<<k<<" "<<ans[i][j].size()<<"\n";
//				for (pii p:ans[i][j]) cerr<<p.XX<<" "<<p.YY<<"\n";
//				cerr<<boost[i][j]<<"\n";
//				cerr<<"\n";
//			}
			ans[i+k][j+k]=ans[i][j];
			ans[i+k][j+k][boost[i][j]].XX+=k;
			ans[i+k][j+k][boost[i][j]].YY+=k;
			k++;
		}
	}
}

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	//0:3
	sets.assign(4, {0, 0});
	sets[0]={0, 3};
	for (int i=23; i>-1; i--) for (int j=23; j>-1; j--) for (int k=23; k>-1; k--)
	{
		sets[1]={i, 25}, sets[2]={j, 25}, sets[3]={k, 25};
		pii c=AB();
		if (boost[c.XX][c.YY]>0) continue;
		ans[c.XX][c.YY]=sets;
		if (i==23) boost[c.XX][c.YY]=1;
		else if (j==23) boost[c.XX][c.YY]=2;
		else if (k==23) boost[c.XX][c.YY]=3;
	}
	flood();
	
	//1:3
	for (int i=0; i<205; i++) for (int j=0; j<205; j++) boost[i][j]=0;
	sets.assign(5, {0, 0});
	sets[0]={1, 3};
	for (int i1=23; i1>-1; i1--) for (int i2=23; i2>-1; i2--)
		for (int i3=23; i3>-1; i3--) for (int i4=23; i4>-1; i4--)
	{
		sets[1]={25, i1}, sets[2]={i2, 25}, sets[3]={i3, 25};
		sets[4]={i4, 25};
		
		pii c=AB();
		if (boost[c.XX][c.YY]>0) continue;
		ans[c.XX][c.YY]=sets;
		if (i1==23) boost[c.XX][c.YY]=1;
		else if (i2==23) boost[c.XX][c.YY]=2;
		else if (i3==23) boost[c.XX][c.YY]=3;
		else if (i4==23) boost[c.XX][c.YY]=4; 
	}
	flood();
	
	//2:3
	for (int i=0; i<205; i++) for (int j=0; j<205; j++) boost[i][j]=0;
	sets.assign(6, {0, 0});
	sets[0]={2, 3};
	for (int i1=23; i1>-1; i1--) for (int i2=23; i2>-1; i2--)
		for (int i3=23; i3>-1; i3--) for (int i4=23; i4>-1; i4--)
			for (int i5=13; i5>-1; i5--)
	{
		sets[1]={25, i1}, sets[2]={25, i2}, sets[3]={i3, 25};
		sets[4]={i4, 25}, sets[5]={i5, 15};
		
		pii c=AB();
		if (boost[c.XX][c.YY]>0) continue;
		ans[c.XX][c.YY]=sets;
		if (i1==23) boost[c.XX][c.YY]=1;
		else if (i2==23) boost[c.XX][c.YY]=2;
		else if (i3==23) boost[c.XX][c.YY]=3;
		else if (i4==23) boost[c.XX][c.YY]=4;
		else if (i5==13) boost[c.XX][c.YY]=5;
	}
	flood();
	
	//3:2
	for (int i=0; i<205; i++) for (int j=0; j<205; j++) boost[i][j]=0;
	sets.assign(6, {0, 0});
	sets[0]={3, 2};
	for (int i1=23; i1>-1; i1--) for (int i2=23; i2>-1; i2--)
		for (int i3=23; i3>-1; i3--) for (int i4=23; i4>-1; i4--)
			for (int i5=13; i5>-1; i5--)
	{
		sets[1]={25, i1}, sets[2]={25, i2}, sets[3]={i3, 25};
		sets[4]={i4, 25}, sets[5]={15, i5};
		
		pii c=AB();
		if (boost[c.XX][c.YY]>0) continue;
		ans[c.XX][c.YY]=sets;
		if (i1==23) boost[c.XX][c.YY]=1;
		else if (i2==23) boost[c.XX][c.YY]=2;
		else if (i3==23) boost[c.XX][c.YY]=3;
		else if (i4==23) boost[c.XX][c.YY]=4;
		else if (i5==13) boost[c.XX][c.YY]=5;
	}
	flood();
	
	//3:1
	for (int i=0; i<205; i++) for (int j=0; j<205; j++) boost[i][j]=0;
	sets.assign(5, {0, 0});
	sets[0]={3, 1};
	for (int i1=23; i1>-1; i1--) for (int i2=23; i2>-1; i2--)
		for (int i3=23; i3>-1; i3--) for (int i4=23; i4>-1; i4--)
	{
		sets[1]={25, i1}, sets[2]={25, i2}, sets[3]={i3, 25};
		sets[4]={25, i4};
		
		pii c=AB();
		if (boost[c.XX][c.YY]>0) continue;
		ans[c.XX][c.YY]=sets;
		if (i1==23) boost[c.XX][c.YY]=1;
		else if (i2==23) boost[c.XX][c.YY]=2;
		else if (i3==23) boost[c.XX][c.YY]=3;
		else if (i4==23) boost[c.XX][c.YY]=4;
	}
	flood();
	
	//3:0
	for (int i=0; i<205; i++) for (int j=0; j<205; j++) boost[i][j]=0;
	sets.assign(4, {0, 0});
	sets[0]={3, 0};
	for (int i1=23; i1>-1; i1--) for (int i2=23; i2>-1; i2--)
		for (int i3=23; i3>-1; i3--)
	{
//		cerr<<i1<<" "<<i2<<" "<<i3<<"\n";
		sets[1]={25, i1}, sets[2]={25, i2}, sets[3]={25, i3};
		
		pii c=AB();
		if (boost[c.XX][c.YY]>0) continue;
		ans[c.XX][c.YY]=sets;
		if (i1==23) boost[c.XX][c.YY]=1;
		else if (i2==23) boost[c.XX][c.YY]=2;
		else if (i3==23) boost[c.XX][c.YY]=3;
	}
	flood();
	
	int m, a, b;
	cin>>m;
	while (m--)
	{
		cin>>a>>b;
		if (ans[a][b].empty()) cout<<"Impossible\n";
		else 
		{
			cout<<ans[a][b][0].XX<<":"<<ans[a][b][0].YY<<endl;
			for (int i=1; i<ans[a][b].size(); i++) 
				cout<<ans[a][b][i].XX<<":"<<ans[a][b][i].YY<<" ";
			cout<<"\n";
		}
	}
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/