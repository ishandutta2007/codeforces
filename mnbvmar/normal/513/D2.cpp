#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 1000005;

int N, C;
vector<int> vleft[MaxN], vright[MaxN];

void input(){
	cin >> N >> C;
	for(int i = 0; i < C; i++){
		int u, v;
		string str;
		cin >> u >> v >> str;

		if(str == "LEFT")
			vleft[u].push_back(v);
		else
			vright[u].push_back(v);
	}
}

int lft[MaxN], rgt[MaxN], last[MaxN];

int curPtr = 0;
bool dfs(int v, int lastPut){
	curPtr++;

	int nextLft = -1;
	for(int s: vleft[v]) nextLft = max(nextLft, s);

	int nextRgt = N+1, maxRgt = -1;
	for(int s: vright[v]){
		nextRgt = min(nextRgt, s);
		maxRgt  = max(maxRgt,  s);
	}
//	cout << "dfs " << v << " " << lastPut << " " << nextLft <<
//	   "     " << nextRgt << " " << maxRgt << endl;
	
	if(nextRgt <= nextLft) return false;

	if(nextLft != -1){
//		cout << v << "L\n";
		lft[v] = curPtr+1;
		if(!dfs(curPtr+1, nextLft)) return false;
	}

	if(curPtr < lastPut || curPtr < maxRgt){
//		cout << v << "R\n";
		rgt[v] = curPtr+1;
		if(!dfs(curPtr+1, max(maxRgt, lastPut))) return false;
	}

	last[v] = curPtr;
	return true;	
}

void output(int v){
	if(lft[v]) output(lft[v]);
	cout << v << " ";
	if(rgt[v]) output(rgt[v]);
}

void bad_end(){
	cout << "IMPOSSIBLE\n";
	exit(0);
}

bool check(){
	for(int v = 1; v <= N; v++){
		if(!vleft[v].empty()){
			if(!lft[v]) return false;
			int minLeft = *min_element(vleft[v].begin(), vleft[v].end());
			int maxLeft = *max_element(vleft[v].begin(), vleft[v].end());
			if(!(v+1 <= minLeft && maxLeft <= last[lft[v]]))
				return false;
		}
		if(!vright[v].empty()){
			if(!rgt[v]) return false;
			int minRight = *min_element(vright[v].begin(), vright[v].end());
			int maxRight = *max_element(vright[v].begin(), vright[v].end());
			if(!(rgt[v] <= minRight && maxRight <= last[rgt[v]]))
				return false;
		}
	}
	return true;
}

int main(){
	input();
	for(int i = 1; i <= N; i++){
		for(int v: vleft[i])
			if(v <= i) bad_end();
		for(int v: vright[i])
			if(v <= i) bad_end();
	}

	if(!dfs(1, N)){
		bad_end();
	}
	if(!check()){
		bad_end();
	}
	output(1);
	cout << endl;
}