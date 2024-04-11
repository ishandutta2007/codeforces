#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 210000
vector<pair<int,int> >e[N];
int used[N];
int c;
bool dfs(int k, int reg,int cc){
	bool re = true;
	used[k] = cc;
	f(i, e[k].size()){
		if (e[k][i].second > reg){
			if (used[e[k][i].first] == cc)return false;
			else if (used[e[k][i].first] == 0)re = dfs(e[k][i].first, reg,cc);
			if (!re)return false;
		}
	}
	used[k] = c;
	c++;
	return true;
}


int main(){
	int as[N];
	int at[N];
	int n, m,k;
	int x, y, z;
	bool v,v2;
	int cc;
	scanf("%d %d", &n,&m);
	f(i, m){
		scanf("%d %d %d", &x, &y, &z);
		x--;
		y--;
		as[i] = x;
		at[i] = y;
		e[x].push_back(make_pair(y, z));
	}
	int l = 0;
	int r = 1000000010;
	int mm;
	while (l + 1 < r){
		mm = (l + r) / 2;
		mm--;
		v = true;
		c = 1;
		cc = 1000000;
		f(i, n)used[i] = 0;
		f(i, n){
			if (used[i] == 0){
				v2 = dfs(i, mm, cc);
				cc++;
				if (!v2){
					v = false;
					break;
				}
			}
		}
		if (v)r = mm + 1;
		else l = mm + 1;
	}
	v = true;
	c = 1;
	cc = 1000000;
	f(i, n)used[i] = 0;
	f(i, n){
		if (used[i] == 0){
			v2 = dfs(i, l, cc);
			cc++;
			if (!v2){
				v = false;
				break;
			}
		}
	}
	vector<int>ans;
	f(i, m){
		if (used[as[i]] < used[at[i]])ans.push_back(i + 1);
	}

	printf("%d %d\n", l,ans.size());
	f(i, ans.size()){
		printf("%d", ans[i]);
		if(i<ans.size()-1)printf(" ");
		else printf("\n");
	}


	return 0;
}