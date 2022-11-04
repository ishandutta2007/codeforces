/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> Pair;

const int maxN= 100*100+100;

bool mark[maxN];
int n,curF, curB;
vector <int> g[maxN];

struct node{
	string s;
	int a;

	node (string _s="", int _a=-1) : s(_s), a(_a) {}

	inline bool operator < (const node &sec) const{
		return s<sec.s;
	}
};
set <node> adj[maxN];
/***************************************/
inline void input(){
	string s;
	n=5;
	while (cin>>s){
		int past= s[0]-'C'+1;
		int poi=0;
		while(s[poi]!='\\')
			poi++;
		poi++;

		while (poi<(int)s.size()){
			int start=poi;
			while (poi<(int)s.size() && s[poi]!='\\')
				poi++;
			node tmp= node(s.substr(start, poi-start),0);
			set<node>::iterator it= adj[past].find(tmp);
			if (it==(adj[past].end())){
				tmp.a= ++n;
				adj[past].insert (tmp);
				g[past].push_back (n);
				past= n;
			}
			else
				past= it->a;
			poi++;
		}
	}
}
/************************************/
inline void dfs (int v){
	mark[v]= true;
	for (int i=0;i<(int)g[v].size();i++){
		int tmp= g[v][i];
		if (!mark[tmp])
			dfs (tmp);
	}
	if (g[v].size())
		curF++;
	else
		curB++;
}
/************************************/
int main(){
	input();
	int maxF=0, maxB=0;
	for (int i=6;i<=n;i++) if(!mark[i]){
		curF=0, curB=0;
		dfs (i);
		curF--;
		maxF= max(maxF, curF);
		maxB= max(maxB, curB);
	}

	cout << maxF << ' ' << maxB << endl;

	return 0;
}