#include <cstdio>
#include <map>
using namespace std;
typedef pair <int, int> pii;
#define fi first
#define se second

struct Solution{
	int val, choice[31];
	bool operator < (const Solution &rhs) const{
		return val < rhs.val;
	}
	Solution operator + (const Solution &rhs) const{
		Solution ret; int i;
		ret.val = val + rhs.val;
		for(i = 1; choice[i]; ++ i) ret.choice[i] = choice[i];
		for(; rhs.choice[i]; ++ i) ret.choice[i] = rhs.choice[i];
		return ret;
	}
}curSol, ans;
typedef pair <pii, Solution> pps;
map <pii, Solution> halfAns;
map <pii, Solution> :: iterator it;
int n, l[31], m[31], w[31], delta1[4][31], delta2[4][31], v[4][31];
pii curDelta;

void dfs1(int dep){
	if(dep == (n + 1) / 2 + 1){
		if((it = halfAns.find(curDelta)) == halfAns.end())
			halfAns.insert(pps(curDelta, curSol));
		else if(it -> second < curSol) halfAns[curDelta] = curSol;
		return;
	}
	for(int i = 1; i <= 3; ++ i){
		curDelta.fi += delta1[i][dep];
		curDelta.se += delta2[i][dep];
		curSol.choice[dep] = i;
		curSol.val += v[i][dep];
		dfs1(dep + 1);
		curDelta.fi -= delta1[i][dep];
		curDelta.se -= delta2[i][dep];
		curSol.choice[dep] = 0;
		curSol.val -= v[i][dep];
	}
}
void update(Solution &a, Solution b){if(a < b) a = b;}
void dfs2(int dep){
	if(dep == n + 1){
		if((it = halfAns.find(pii(- curDelta.fi, - curDelta.se))) != halfAns.end())
			update(ans, (it -> se) + curSol);
		return;
	}
	for(int i = 1; i <= 3; ++ i){
		curDelta.fi += delta1[i][dep];
		curDelta.se += delta2[i][dep];
		curSol.choice[dep] = i;
		curSol.val += v[i][dep];
		dfs2(dep + 1);
		curDelta.fi -= delta1[i][dep];
		curDelta.se -= delta2[i][dep];
		curSol.choice[dep] = 0;
		curSol.val -= v[i][dep];
	}
}
int main(){
	ans.val = -0x3f3f3f3f;
	int i, x, y, z;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d%d%d", &x, &y, &z);
		delta1[1][i] = - y;
		delta2[1][i] = y - z;
		v[1][i] = 0;
		delta1[2][i] = x;
		delta2[2][i] = - z;
		v[2][i] = x;
		delta1[3][i] = x - y;
		delta2[3][i] = y;
		v[3][i] = x;
	}
	dfs1(1);
	dfs2((n + 1) / 2 + 1);
	if(ans.val == -0x3f3f3f3f) printf("Impossible\n");
	else{
		for(i = 1; i <= n; ++ i)
			switch(ans.choice[i]){
				case 1: printf("MW\n"); break;
				case 2: printf("LW\n"); break;
				case 3: printf("LM\n"); break;
			}
	}
	return 0;
}