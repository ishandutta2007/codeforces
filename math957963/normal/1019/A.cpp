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
#define N 30010


int main(){
	vector<long long>a[N];
	vector<bool>used[N];
	vector<pair<long long, pair<int, int> > >b;
	int n, m, k, x;
	long long s, ans;
	ans = 100000000000000000;
	scanf("%d %d", &n, &m);
	k = 0;
	f(i, n){
		scanf("%d %I64d", &x, &s);
		a[x].push_back(s);
		if (x == 1)k++;
		used[x].push_back(false);
	}
	f(i, m - 1){
		sort(a[i + 2].begin(), a[i + 2].end());
		f(j, a[i + 2].size()){
			b.push_back(make_pair(a[i + 2][j], make_pair(i + 2, j)));
		}
	}
	if(m>1){
sort(b.begin(), b.end());
	for (int i = a[1].size(); i<(n / 2) + 2; i++){
		if (i > 0&&i<=n){
			x = 0;
			s = 0;
			f(j, m - 1){
				f(ii, a[j + 2].size() - i + 1){
					x++;
					s += a[j + 2][ii];
					used[j + 2][ii] = true;
				}
			}
			f(j, b.size()){
				if (k + x < i){
					if (!used[b[j].second.first][b[j].second.second]){
						x++;
						s += b[j].first;
					}
				}
			}
			if (k + x >= i)ans = min(ans, s);
			f(j, m - 1){
				f(ii, a[j + 2].size() - i + 1){
					used[j + 2][ii] = false;
				}
			}

		}
	}

	printf("%I64d\n", ans);
}
else printf("0\n");


	return 0;
}