#include <cstdio>
#include <iostream>
#include <cmath> 
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
const int N = 200010;
int n, k, a[N];
priority_queue<PII, vector<PII>, greater<PII> > q;
int main(){
	int T; scanf("%d", &T);
	while(T--){
		while(q.size()) q.pop();
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++)
			scanf("%d", a + i);	
		for(int i = 1; i + k <= n; i++)
			q.push(make_pair(a[i + k] - a[i], (a[i] + a[i + k]) / 2));
		printf("%d\n", q.top().second);
	}
	return 0;
}