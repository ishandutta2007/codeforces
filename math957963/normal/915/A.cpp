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

int main(){
	vector<int>a;
	int n, k;
	int x, y, z;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		a.push_back(x);
	}
	sort(a.begin(), a.end(), greater<int>());
	for (int i = 0; i < n; i++){
		if (k%a[i] == 0){
			printf("%d\n", (k / a[i]));

			return 0;
		}
	}

	return 0;
}