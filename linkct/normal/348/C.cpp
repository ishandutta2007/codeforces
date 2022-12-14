#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long int ll;
const int MAXN = 100005, SQRT = 320;

struct Set{
	vector <int> data;
	ll delta, sum; int id;
}sets[MAXN];
vector <bool> exist[SQRT];
int back[SQRT], n, m, q, intersect[MAXN][SQRT], index, sq;
ll seq[MAXN];

int main(){
	int i, j, k, t; char op[5]; ll ans;
	scanf("%d%d%d", &n, &m, &q);
	sq = int(sqrt(double(n)) + 1e-8);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &t);
		seq[i] = t;
	}
	for(i = 1; i <= m; ++ i){
		scanf("%d", &k);
		for(j = 1; j <= k; ++ j){
			scanf("%d", &t);
			sets[i].data.push_back(t);
		}
		if(sets[i].data.size() >= sq){
			sets[i].id = ++ index;
			back[index] = i;
			exist[index].resize(n + 1);
			for(j = 0; j < sets[i].data.size(); ++ j)
				exist[index][sets[i].data[j]] = true;
		}
	}
	for(i = 1; i <= m; ++ i){
		for(j = 0; j < sets[i].data.size(); ++ j)
			for(k = 1; k <= index; ++ k)
				if(exist[k][sets[i].data[j]])
					intersect[i][k] ++;
		if(sets[i].data.size() >= sq)
			for(j = 0; j < sets[i].data.size(); ++ j)
				sets[i].sum += seq[sets[i].data[j]];
	}
	for(i = 1; i <= q; ++ i){
		scanf("%s%d", op, &k);
		if(op[0] == '?'){
			if(sets[k].data.size() >= sq) ans = sets[k].sum;
			else for(j = ans = 0; j < sets[k].data.size(); ++ j)
				ans += seq[sets[k].data[j]];
			for(j = 1; j <= index; ++ j)
				ans += sets[back[j]].delta * intersect[k][j];
			printf("%I64d\n", ans);
		}else{
			scanf("%d", &t);
			if(sets[k].data.size() >= sq) sets[k].delta += t;
			else{
				for(j = ans = 0; j < sets[k].data.size(); ++ j)
					seq[sets[k].data[j]] += t;
				for(j = 1; j <= index; ++ j)
					sets[back[j]].sum += ll(t) * intersect[k][j];
			}
		}
	}
	return 0;
}