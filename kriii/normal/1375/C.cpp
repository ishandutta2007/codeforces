#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
using namespace std;

int n, a[300300], mn[300300], mx[300300];

int main()
{
	int t; scanf ("%d", &t); while (t--){
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%d", &a[i]);

		stack<int> s; s.push(n + 1);
		for (int i = 0; i < n; i++){
			int mn = a[i];
			while (1){
				if (s.top() > a[i]) break;
				mn = s.top(); s.pop();
			}
			s.push(mn);
		}

		puts(s.size() == 2 ? "YES" : "NO");
	}
	return 0;
}