#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int m, n;
int hp[1000005];
vector<int> vec;
int g[1000005];

int main(void)
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) scanf("%d", &hp[i]);
	
	int sum = 0;
	for(int i = 1; i < m; i++){
		sum += hp[i], sum %= n;
		if(sum > 0) vec.push_back(sum);
	}
	vec.push_back(n);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	
	int sumhp = 0;
	for(int i = 1; i <= m; i++) sumhp += hp[i];
	int T = (sumhp+n-1) / n;
	printf("%d\n", T);
	
	int pre = 0;
	for(int i = 0; i < vec.size(); i++){
		g[i+1] = vec[i] - pre;
		pre = vec[i];
	}
	for(int i = 1; i <= m; i++) printf("%d ", g[i]); printf("\n");
	
	int nx = 1;
	for(int t = 0; t < T; t++){
		for(int i = 1; i <= m; i++){
			if(nx > m){
				printf("1 ");
				continue;
			}
			hp[nx] -= g[i]; printf("%d ", nx);
			if(hp[nx] <= 0) nx++;
		}
		printf("\n");
	}
	
	return 0;
}