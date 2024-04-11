#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
const int N = 200005;
int n, p[N], L[N], R[N], pos[N], ans = 0;
stack<int> s;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", p + i), pos[p[i]] = i;
	
	
	for (int i = 1; i <= n; i++) R[i] = n + 1;
	for (int i = 1; i <= n; i++) {
		while(s.size() && p[s.top()] < p[i]) {
			R[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	
	while(s.size()) s.pop();
	for (int i = n; i; i--) {
		while(s.size() && p[s.top()] < p[i]) {
			L[s.top()] = i, s.pop();
		}
		s.push(i);
	}
	for (int i = 1; i <= n; i++) {
		if(i - L[i] < R[i] - i) {
			for (int j = L[i] + 1; j < i; j++)
				if(i < pos[p[i] - p[j]] && pos[p[i] - p[j]] < R[i])
					ans++;
		} else {
			for (int j = i + 1; j < R[i]; j++)
				if(L[i] < pos[p[i] - p[j]] && pos[p[i] - p[j]] < i)
					ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}