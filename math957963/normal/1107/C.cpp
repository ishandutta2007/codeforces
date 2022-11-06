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
#define N 200000


int main(){
	long long b[N + 1];
	char a[N + 1];
	f(i, N + 1){
		a[i] = 0;
		b[i] = 0;
	}
	vector<long long>c;
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n,&k);
	f(i, n)scanf("%I64d", &b[i]);
	scanf("%s", a);
	ans = 0;
	c.push_back(b[0]);
	f(i, n - 1){
		if (a[i] != a[i + 1]){
			sort(c.begin(), c.end(), greater<long long>());
			f(i, c.size()){
				if (i < k)ans += c[i];
			}
			c.clear();
		}
		c.push_back(b[i+1]);
	}
	sort(c.begin(), c.end(), greater<long long>());
	f(i, c.size()){
		if (i < k)ans += c[i];
	}
	c.clear();
	printf("%I64d\n", ans);

	return 0;
}