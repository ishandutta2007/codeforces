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
#define N (200010)



int n, m;
vector<int>e[N];
bool used[N];

void init(void){
	memset(used, 0, sizeof(used));
	return;
}


int main(void){
	int k;
	int a[N];
	int x, y;
	long long z;
	long long s, ans;
	queue<int>q;
	scanf("%d", &n);
	init();
	f(i, n - 1){
		scanf("%d %d", &x, &y);
		x--;
		y--;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	f(i, n){
		scanf("%d", &a[i]);
		a[i]--;
	}
	if (a[0] != 0){
		printf("No\n");
		return 0;
	}
	used[0] = true;
	q.push(0);
	y = 1;
	f(i, n){
if(q.empty()){
		printf("No\n");
		return 0;
	}
		x = q.front();
		k = 0;
		f(i, e[x].size()){
			if (!used[e[x][i]])k++;
		}
		f(i, k){
			if (y < n){
				if (used[a[y]]){
					printf("No\n");
					return 0;
				}
				used[a[y]] = true;
				q.push(a[y]);
				y++;
			}
			else{
				printf("No\n");
				return 0;
			}
		}
		f(i, e[x].size()){
			if (!used[e[x][i]]){
				printf("No\n");
				return 0;
			}
		}
		q.pop();
	}

	printf("Yes\n");

	return 0;
}