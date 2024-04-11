#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 100005;

vector <int> doll[MAXN];
int n, k, cnt[MAXN], ans;

int main(){
	int i, j, t;
	scanf("%d%d", &n, &k);
	for(i = 1; i <= k; ++ i){
		scanf("%d", &cnt[i]);
		ans += cnt[i] - 1;
		for(j = 1; j <= cnt[i]; ++ j){
			scanf("%d", &t);
			doll[i].push_back(t);
		}
	}
	for(i = 1; i <= k; ++ i)
		if(doll[i][0] == 1){
			ans -= cnt[i] - 1;
			for(j = 0; j + 1 < doll[i].size(); ++ j)
				if(doll[i][j + 1] != j + 2) break;
			printf("%d\n", doll[i].size() - j - 1 + n - j - 1 + ans);
			break;
		}
	return 0;
}