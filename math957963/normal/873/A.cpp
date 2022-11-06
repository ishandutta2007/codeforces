#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int main(void){
	int a[100];
	int k;
	int n;
	int s;
	int x;


	scanf("%d %d %d", &n,&k,&x);

	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	s = 0;
	for (int i = 0; i < n-k; i++){
		s = s + a[i];
	}
	s += (x*k);
	printf("%d", s);

	return 0;
}