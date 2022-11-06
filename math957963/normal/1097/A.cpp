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
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 200000

int main(){
	char a[3];
	char b[10][3];
	f(i, 10){
		f(j, 3){
			a[j] = 0;
			b[i][j] = 0;
		}
	}
	scanf("%s", a);
	f(i, 5)scanf("%s", b[i]);
	bool v = false;
	f(i, 5){
		if (a[0] == b[i][0] || a[1] == b[i][1])v = true;
	}
	
	if(v)printf("YES\n");
	else printf("NO\n");


	return 0;
}