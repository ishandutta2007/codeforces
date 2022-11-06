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
#define N 1000100


int main(){
	char a[N + 1];
	char b[N + 1];
	char c[N + 1];
	f(i, N + 1){
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
	}
	int ans[30];
	bool used[30];
	vector<pair<int, int> >d;
	int n, k,t;
	int x, y, z;
	long long s;
	bool v = true;
	bool vv;
	scanf("%d", &t);
	f(tt, t){
		scanf("%d", &k);
		scanf("%s", c);
		scanf("%s", a);
		scanf("%s", b);
		n = strlen(a);
		z = 0;
		f(i, 30){
			ans[i] = -1;
			used[i] = false;
		}
		d.clear();
		vv = true;
		f(i, n){
			if (ans[c[i] - 97] == -1){
				v = false;
				for (int j = a[i] - 97; j < k; j++){
					if (!used[j]){
						v = true;
						used[j] = true;
						ans[c[i] - 97] = j;
						d.push_back(make_pair(c[i] - 97, j));
						break;
					}
				}
				if (v){
					if (ans[c[i] - 97] > a[i] - 97)break;
				}
				else{
					for (int j = d.size() - 1; j >= 0; j--){
						used[d[j].second] = false;
						ans[d[j].first] = -1;
						for (int ii = d[j].second + 1; ii < k; ii++){
							if (!used[ii]){
								v = true;
								used[ii] = true;
								ans[d[j].first] = ii;
								break;
							}
						}
						if (v)break;
					}
					if (v){
						break;
					}
					else{
						vv = false;
						break;
					}
				}
			}
			else{
				if (ans[c[i] - 97] > a[i] - 97){
					break;
				}
				else if (ans[c[i] - 97] < a[i] - 97){
					v = false;

					for (int j = d.size() - 1; j >= 0; j--){
						used[d[j].second] = false;
						ans[d[j].first] = -1;
						for (int ii = d[j].second + 1; ii < k; ii++){
							if (!used[ii]){
								v = true;
								used[ii] = true;
								ans[d[j].first] = ii;
								break;
							}
						}
						if (v)break;
					}
					if (v){
						break;
					}
					else{
						vv = false;
						break;
					}
				}
			}
		}
		f(i, n){
			if (ans[c[i] - 97] == -1){
				f(j, k){
					if (!used[j]){
						ans[c[i] - 97] = j;
						used[j] = true;
						break;
					}
				}
			}
		}
		f(i, k){
			if (ans[i] == -1){
				f(j, k){
					if (!used[j]){
						ans[i] = j;
						used[j] = true;
						break;
					}
				}
			}
		}
		if (!vv)printf("NO\n");
		else{
			f(i, n){
				if (ans[c[i] - 97] < b[i] - 97)break;
				else if (ans[c[i] - 97] > b[i] - 97){
					vv = false;
					break;
				}
			}
			if (!vv)printf("NO\n");
			else{
				printf("YES\n");
				f(i, k)printf("%c", ans[i] + 97);
				printf("\n");
			}
		}

		f(i, n + 1){
			a[i] = 0;
			b[i] = 0;
			c[i] = 0;
		}
	}

	return 0;
}