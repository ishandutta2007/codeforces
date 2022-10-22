#include <bits/stdc++.h>
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define mp make_pair
#define sz(a) int((a).size())
#define pi pair<int, int>
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 1e5 + 10;
int a, b;
int note[N], tot = 0, vis[N];
int main() {
	cin >> a >> b;
	int s = a + b, k = 1;
	for(; s >= k; s -= k, note[++tot] = k, k++);
	s = a, k = 1;
	for(; s >= k; s -= k, vis[k] = 1, k++);
	k--;
	int d = tot - k;
	for(int i = k; i >= 1 && s; i--) {
		vis[i] = 0;
		vis[i + min(s, d)] = 1;
		s -= min(s, d);
	}
	int sze = 0;
	for(int i = 1; i <= tot; i++) if(vis[i]) sze++;
	cout << sze << endl;
	for(int i = 1; i <= tot; i++) if(vis[i]) cout << i <<" ";
	cout << endl;
	cout << tot - sze << endl;
	for(int i = 1; i <= tot; i++) if(!vis[i]) cout << i <<" ";
	cout << endl;
	return 0;
}