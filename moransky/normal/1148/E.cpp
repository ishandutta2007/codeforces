#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
typedef long long LL;

const int N = 300005;
int n, tot = 0, t[N];
LL sum[N];
PII s[N];

struct Ans{
	int i, j, d;
}ans[N];
bool check() {
	for(int i = 1; i < n; i++)
		if(sum[i] > 0) return false;
	return sum[n] == 0;
}


stack<int> st;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &s[i].first), s[i].second = i;
	for (int i = 1; i <= n; i++)
		scanf("%d", t + i);
		
	sort(s + 1, s + 1 + n);
	sort(t + 1, t + 1 + n);
	
	for(int i = 1; i <= n; i++) 
		sum[i] = sum[i - 1] + s[i].first - t[i];
	
	if(!check()) { puts("NO"); return 0; }
	for(int i = 1; i <= n; i++) {
		if(s[i].first < t[i]) {
			st.push(i);
		} else if(s[i].first > t[i]) {
			int x = s[i].first - t[i];
			while(x) {
				int u = st.top();
				int val = min(x, t[u] - s[u].first);
				ans[++tot] = (Ans) { s[u].second, s[i].second, val };
				s[u].first += val;
				x -= val;
				if(s[u].first == t[u]) st.pop();
			}
		}
	}
	if(!st.empty()) { puts("NO"); return 0; }
	printf("YES\n%d\n", tot);
	for(int i = 1; i <= tot; i++)
		printf("%d %d %d\n", ans[i].i, ans[i].j, ans[i].d);
    return 0;
}