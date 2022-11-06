#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<queue>
#include<set>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define MOD 1000000009

int main(void){
	int k, s;
	int n, m;
	int x, y, z;
	int ans = 0;
	set<int> g1;
	vector<int>b1;
	set<int> g2;
	vector<int>b2;

scanf("%d %d", &n,&m);
	g1.insert(0);
	b1.push_back(0);
	g2.insert(0);
	b2.push_back(0);
	f(i, n/2){
		scanf("%d", &x);
z=b1.size();
		for (int i = 0; i < z; i++){
			y = (x + b1[i]) % m;
			if (!g1.count(y)){
				g1.insert(y);
				b1.push_back(y);
			}
		}
	}
	f(i, n - (n / 2)){
		scanf("%d", &x);
z=b2.size();
		for (int i = 0; i < z; i++){
			y = (x + b2[i]) % m;
			if (!g2.count(y)){
				g2.insert(y);
				b2.push_back(y);
			}
		}
	}
	sort(b1.begin(), b1.end());
	sort(b2.begin(), b2.end(), greater<int>());
	x = 0;
	y = 0;
	for (; x < b1.size() && y < b2.size();){
		z = (b1[x] + b2[y]) % m;
		if (ans < z)ans = z;
		if (b1[x] + b2[y] >= m)y++;
		else x++;
	}

	printf("%d\n", ans);

	return 0;
}