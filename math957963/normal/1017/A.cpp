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
#define N 200000


int main(){
	vector<int>a;
	int n, k;
	int w, x, y, z;
	scanf("%d", &n);
	f(i, n){
		scanf("%d %d %d %d", &x,&w,&y,&z);
		if (i == 0)k = w + x + y + z;
		a.push_back(w + x + y + z);
	}
	sort(a.begin(), a.end(), greater<int>());

	f(i, n){
		if (a[i] == k){
			printf("%d\n", i + 1);
			return 0;
		}
	}
	return 0;
}