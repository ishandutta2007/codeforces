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
#define N 2000


int main(){
	int a[N];
	int l[N];
	int r[N];
	bool used[N];
	vector<int>b;
	f(i, N){
		a[i] = 0;
		l[i] = 0;
		r[i] = 0;
		used[i] = false;
	}
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, 2*n){
		scanf("%d", &a[i]);
		if (!used[a[i]]){
			used[a[i]] = true;
			l[a[i]] = i;
			b.push_back(a[i]);
		}
		else{
			r[a[i]] = i;
		}
	}
	f(i, n){
		ans += r[b[i]] - l[b[i]] - 1;
		for (int j = i + 1; j < n; j++){
			if (r[b[j]] < r[b[i]])r[b[j]]++;
			if (l[b[j]] < r[b[i]])l[b[j]]++;
		}
		r[b[i]] = l[b[i]] + 1;
	}

	printf("%d\n", ans);


	return 0;
}