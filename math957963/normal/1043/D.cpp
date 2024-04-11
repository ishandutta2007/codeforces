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
#define N 120000


int main(){
	int a[N];
	int b[N];
	int nb[N];
	int s[N];
	int ns[N];
	f(i, N){
		a[i] = 0;
		b[i] = -1;
		s[i] = -1;
	}
	int n, m, k;
	int x, y, z;
	long long ss, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n,&m);
	f(i, n){
		scanf("%d", &a[i]);
		a[i]--;
		if (i > 0){
			s[a[i - 1]] = a[i];
			b[a[i]] = a[i - 1];
		}
	}
	f(j, m - 1){
		f(i, n){
			nb[i] = -1;
			ns[i] = -1;
		}
		f(i, n){
			scanf("%d", &a[i]);
			a[i]--;
			if (i > 0){
					ns[a[i - 1]] = a[i];
					nb[a[i]] = a[i - 1];
			}
		}
		f(i, n){
			if (s[i] != ns[i])s[i] = -1;
			if (b[i] != nb[i])b[i] = -1;
		}
	}
	f(i, n){
		if (b[i] == -1){
			ss = 1;
			x = i;
			while (s[x] >= 0){
				ss++;
				x = s[x];
			}
			ss = (ss*(ss + 1)) / 2;
			ans += ss;
		}
	}

	printf("%I64d\n", ans);


	return 0;
}