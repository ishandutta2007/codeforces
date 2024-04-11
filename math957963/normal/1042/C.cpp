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
#define N 400000


int main(){
	int a[N];
	f(i, N)a[i] = 0;
	bool b[N];
	f(i, N)b[i] = false;
	vector<int> c;
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	x = -1;
	y = -1000010000;
	z = 0;
	scanf("%d", &n);
	f(i, n){
		scanf("%d", &a[i]);
		if (a[i] < 0){
			z++;
			if (y < a[i]){
				x = i;
				y = a[i];
			}
		}
		else if (a[i] == 0)c.push_back(i);
		b[i] = true;
	}

	if (z % 2 != 0){
		if (c.size() >= n-1)c[n - 2] = x;
		else c.push_back(x);
	}
	else if (c.size() == n){
		c[n - 1] = -1;
	}
	if(!c.empty())sort(c.begin(), c.end());
	f(i, c.size() - 1){
		if (c[i] != -1 && c[i + 1] != -1){
			printf("1 %d %d\n", c[i] + 1, c[i + 1] + 1);
			b[c[i]] = false;
		}
	}
	if (c.size()>0){
		if (c[c.size() - 1] != -1){
			printf("2 %d\n", c[c.size() - 1] + 1);
			b[c[c.size() - 1]] = false;
		}
	}
	c.clear();
	f(i, n){
		if (b[i])c.push_back(i);
	}
	f(i, c.size() - 1){
		printf("1 %d %d\n", c[i] + 1, c[i + 1] + 1);
	}



	return 0;
}