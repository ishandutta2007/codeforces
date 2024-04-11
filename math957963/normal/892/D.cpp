#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define MOD 1000000009

bool judge(int n, vector<long long> a,vector<long long> b){
	long long s1, s2;
	int x;
	int k = 1 << (n-1);
	for(int i=1;i<k;i++){
		s1 = 0;
		s2 = 0;
		x = i;
		for (int j = 0; j < n-1; j++){
			if (x % 2 == 1){
				s1 += a[j];
				s2 += b[j];
			}
			x = x / 2;
		}
		if (s1 == s2)return false;
	}
	return true;
}


int main(void){
	vector<long long>a;
	long long s = 0;
	int k, n;
	long long x;
	vector<long long> ans;
	vector<pair<long long, int> >so;
	bool z;

	scanf("%d", &n);

	f(i, n){
		scanf("%I64d", &x);
		a.push_back(x);
		ans.push_back(x);
		so.push_back(make_pair(x, i));
	}
	z = false;
	f(i, n){
		x = ans[0];
		f(j, n - 1)ans[j] = ans[j + 1];
		ans[n - 1] = x;
		z = judge(n, a, ans);
		if (z == true){
			f(j, n){
				if (j < n - 1)printf("%I64d ", ans[j]);
				else printf("%I64d\n", ans[j]);
			}
			break;
		}
	}
	if (z == false){
		sort(so.begin(), so.end());
		f(i, n - 1){
			ans[so[i].second] = a[so[i + 1].second];
		}
		ans[so[n-1].second] = a[so[0].second];
		z = judge(n, a, ans);
		if (z == true){
			f(j, n){
				if (j < n - 1)printf("%I64d ", ans[j]);
				else printf("%I64d\n", ans[j]);
			}
		}
	}
	if (z == false){
		printf("-1\n");
	}
	
	return 0;
}