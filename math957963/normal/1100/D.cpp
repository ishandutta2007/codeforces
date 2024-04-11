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
#define N 200000
#define PI (3.1415926535898)

int main(){
	int a[1000][1000];
	f(i, 1000){
		f(j, 1000)a[i][j] = 0;
	}
	int n,m;
	int bx[1000];
	int by[1000];
	int k;
	int x;
	int y;
	scanf("%d %d", &n,&m);
	a[n][m] = 1000;
	f(i, 666){
		scanf("%d %d", &bx[i+1], &by[i+1]);
		a[bx[i + 1]][by[i + 1]] = i + 1;
	}
	while (n != 500 || m != 500){
		if (n < 500){
			a[n][m] = 0;
			n++;
			printf("%d %d\n", n, m);
			fflush(stdout);
			a[n][m] = 1000;
		}
		else if (n>500){
			a[n][m] = 0;
			n--;
			printf("%d %d\n", n, m);
			fflush(stdout);
			a[n][m] = 1000;
		}
		else if (m < 500){
			a[n][m] = 0;
			m++;
			printf("%d %d\n", n, m);
			fflush(stdout);
			a[n][m] = 1000;
		}
		else{
			a[n][m] = 0;
			m--;
			printf("%d %d\n", n, m);
			fflush(stdout);
			a[n][m] = 1000;
		}
		scanf("%d %d %d", &k, &x, &y);
		if (k == -1)return 0;
		a[bx[k]][by[k]] = 0;
		bx[k] = x;
		by[k] = y;
		a[bx[k]][by[k]] = k;
	}
	int ul, ur, dl, dr;
	ul = 0;
	ur = 0;
	dl = 0;
	dr = 0;
	f(i, 1000){
		f(j, 1000){
			if (a[i][j]>0 && a[i][j] < 1000){
				if (i < 500 && j < 500)ul++;
				else if (i < 500 && j > 500)ur++;
				else if (i > 500 && j < 500)dl++;
				else if (i > 500 && j > 500)dr++;
			}
		}
	}
	if (ul < 167){
		while (true){
			if (a[n + 1][m + 1] == 0){
				a[n][m] = 0;
				n++;
				m++;
				printf("%d %d\n", n, m);
				fflush(stdout);
				a[n][m] = 1000;
			}
			else{
				a[n][m] = 0;
				n++;
				printf("%d %d\n", n, m);
				fflush(stdout);
				a[n][m] = 1000;
			}
			scanf("%d %d %d", &k, &x, &y);
			if (k == -1)return 0;
			a[bx[k]][by[k]] = 0;
			bx[k] = x;
			by[k] = y;
			a[bx[k]][by[k]] = k;
		}
	}
	else if (ur < 167){
		while (true){
			if (a[n + 1][m - 1] == 0){
				a[n][m] = 0;
				n++;
				m--;
				printf("%d %d\n", n, m);
				fflush(stdout);
				a[n][m] = 1000;
			}
			else{
				a[n][m] = 0;
				n++;
				printf("%d %d\n", n, m);
				fflush(stdout);
				a[n][m] = 1000;
			}
			scanf("%d %d %d", &k, &x, &y);
			if (k == -1)return 0;
			a[bx[k]][by[k]] = 0;
			bx[k] = x;
			by[k] = y;
			a[bx[k]][by[k]] = k;
		}
	}
	else if (dl < 167){
		while (true){
			if (a[n - 1][m + 1] == 0){
				a[n][m] = 0;
				n--;
				m++;
				printf("%d %d\n", n, m);
				fflush(stdout);
				a[n][m] = 1000;
			}
			else{
				a[n][m] = 0;
				n--;
				printf("%d %d\n", n, m);
				fflush(stdout);
				a[n][m] = 1000;
			}
			scanf("%d %d %d", &k, &x, &y);
			if (k == -1)return 0;
			a[bx[k]][by[k]] = 0;
			bx[k] = x;
			by[k] = y;
			a[bx[k]][by[k]] = k;
		}
	}
	else{
		while (true){
			if (a[n - 1][m - 1] == 0){
				a[n][m] = 0;
				n--;
				m--;
				printf("%d %d\n", n, m);
				fflush(stdout);
				a[n][m] = 1000;
			}
			else{
				a[n][m] = 0;
				n--;
				printf("%d %d\n", n, m);
				fflush(stdout);
				a[n][m] = 1000;
			}
			scanf("%d %d %d", &k, &x, &y);
			if (k == -1)return 0;
			a[bx[k]][by[k]] = 0;
			bx[k] = x;
			by[k] = y;
			a[bx[k]][by[k]] = k;
		}
	}


	return 0;
}