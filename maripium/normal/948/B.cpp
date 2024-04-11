#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

bool np[N];
vector<int> pr;
int f[N];

void eratos() {
	np[0] = np[1] = 2;
	for(int i = 2;i < N;++i) {
		if(np[i]) continue;
		for(int j = i;j < N;j += i) f[j] = max(f[j],i);
		for(int j = i << 1;j < N;j += i) np[j] = 1;
	} 
}
int main() {
	eratos();
	int x2;
	cin >> x2;
	int ans = 123456789;
	for(int i = x2 - f[x2] + 1;i <= x2;++i) {
		if(np[i])ans = min(ans,i - f[i] + 1);
		//cout << ans << endl;
	}
	cout << ans << endl;
}