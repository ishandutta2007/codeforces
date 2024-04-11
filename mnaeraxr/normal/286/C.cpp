#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; scanf("%d", &n);
	
	vector<int> v(n);
	
	for (int i = 0; i < n; ++i)
		scanf("%d", &v[i]);
		
	int neg; scanf("%d", &neg);
	
	for (int i = 0; i < neg; ++i){
		int idx; scanf("%d", &idx);
		v[idx - 1] *= -1;
	}
	
	stack<int> s;
	
	for (int i = n - 1; ~i; --i){
		if (v[i] < 0){
			s.push(-v[i]);
		}
		else{		
			if (s.empty() || s.top() != v[i]){
				s.push(v[i]);
				v[i] *= -1;
			}
			else{
				s.pop();
			}
		}
	}
	
	if (s.empty()){
		printf("YES\n");
		for (int i = 0; i < n; ++i)
			printf("%d ", v[i]);
		putchar('\n');
	}
	else
		printf("NO\n");
}