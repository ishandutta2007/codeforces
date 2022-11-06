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
	char a[N + 1];
	f(i, N + 1)a[i] = 0;
	int b[30];
	f(i, 30)b[i] = 0;
	int n;
	bool v = false;
	scanf("%d", &n);
	scanf("%s", a);
	if (n == 1)printf("Yes\n");
	else{
		f(i, n){
			b[a[i] - 97]++;
		}
		f(i, 30){
			if (b[i] > 1)v = true;
		}
		if (v)printf("Yes\n");
		else printf("No\n");
	}



	return 0;
}