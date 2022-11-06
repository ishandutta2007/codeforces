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
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200001

int b[N];
vector<int>e[N];

void dfs(int x, int k){
	b[x] = k;
	f(i, e[x].size()){
		if (b[e[x][i]] == -1)dfs(e[x][i], k);
	}
	return;
}

int main(){
	vector<int> a[N];
	f(i, N){
		b[i] = -1;
	}
	int n, k;
	int h, w, m;
	int x, y;
	int ans;
	ans = -1;
	scanf("%d %d %d", &h, &w, &m);
	f(i, m){
		scanf("%d %d", &x, &y);
		x--;
		y--;
		a[x].push_back(y);
	}
	f(i, h){
		if (a[i].size() > 0){
			f(j, a[i].size()-1){
				e[a[i][0]].push_back(a[i][j + 1]);
				e[a[i][j + 1]].push_back(a[i][0]);
			}
		}
		else ans++;
	}

	k = 0;
	f(i, w){
		if (b[i] == -1){
			dfs(i, k);
			k++;
		}
	}
	ans += k;
	printf("%d\n", ans);

	return 0;
}