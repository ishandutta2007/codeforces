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
	int n;
	int ax, ay, bx, by, cx, cy;
	scanf("%d", &n);
	scanf("%d %d", &ax, &ay);
	scanf("%d %d", &bx, &by);
	scanf("%d %d", &cx, &cy);
	if (bx < ax&&by < ay){
		if (cx < ax&&cy < ay)printf("YES\n");
		else printf("NO\n");
	}
	else if (bx > ax&&by < ay){
		if (cx > ax&&cy < ay)printf("YES\n");
		else printf("NO\n");
	}
	else if (bx < ax&&by > ay){
		if (cx < ax&&cy > ay)printf("YES\n");
		else printf("NO\n");
	}
	else {
		if (cx > ax&&cy > ay)printf("YES\n");
		else printf("NO\n");
	}
		return 0;
}