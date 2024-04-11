#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int main(void){
	priority_queue<int>pq;
	vector<int>a;
	int k;
	int n;
	int x,y,z;
	int s;


	scanf("%d %d", &n,&k);
	if (k > 2 * n || k % 2 == 0){
		printf("-1");
		return 0;
	}
	pq.push(0);
	pq.push(-n);
	k = (k - 1) / 2;
	x = 0;
	for (int i = 0; i < k; i++){
		z = 0;
		x = -pq.top();
			pq.pop();
			y = -pq.top();
		for (; z == 0;){
			if (y-x>1){
				pq.push(-((x + y) / 2));
				pq.push(-x);
				z++;
			}
			else {
				a.push_back(x);
				x = y;
				pq.pop();
				y = -pq.top();
			}
		}
	}
	while (pq.empty() == 0){
		a.push_back(-pq.top());
		pq.pop();
	}
	s = 0;
	for (int i = 0; i < k+1; i++){
		for (int j = n - a[i + 1]+1; j < n - a[i]+1; j++){
			printf("%d", j);
			s++;
			if (s < n)printf(" ");
		}
	}

	return 0;
}