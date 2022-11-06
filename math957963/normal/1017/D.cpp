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
#define N 8192


int main(){
	int a[N][1201];
	int b[N];
	int mi[N];
	char c[15];
	int d[15];
	int e[N];
	f(i, N){
		b[i] = 0;
		mi[i] = 1000000000;
	}
	int n, m, q, k;
	int x, y, z;
	int l, r, mid;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d %d", &n, &m, &q);
	f(i, n)scanf("%d", &d[i]);
	f(i, m){
		scanf("%s", c);
		x = 1;
		k = 0;
		f(j, n){
			if (c[j] == '1')k += x;
			x = x * 2;
		}
		b[k]++;
	}
	k = 1 << n;

	f(i, k){
		x = i;
		y = 0;
		z = 0;
		f(j, k)e[j] = 0;
		f(j, n){
			f(li, 1 << (j)){
				if (x % 2 == 0){
					e[li + (1 << j)] = e[li];
					e[li] += d[j];
				}
				else{
					e[li + (1 << j)] = e[li];
					e[li + (1 << j)] += d[j];
				}
			}
			x = x / 2;
		}
		f(j, k){
			a[i][e[j]] += b[j];
		}
		f(j, 1200){
			a[i][j + 1] = a[i][j] + a[i][j+1];
		}

	}
	f(qq, q){
		scanf("%s %d", c, &z);
		x = 1;
		y = 0;
		f(i, n){
			if (c[i] == '1')y += x;
			x = x * 2;
		}

			printf("%d\n", a[y][z]);

	}


	return 0;
}