# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>

using namespace std;

const int maxn = 500010;
vector<int> a[maxn];
int mu[maxn], f[maxn], s[maxn];
int lb[(1<<19)+1];

int init(vector<int> &vec) {
	int m; scanf("%d", &m);
	vector<int> v;
	for(int i = 2; i * i <= m; ++i) if(m%i==0) {
		v.push_back(i);
		while(m % i == 0) m /= i;
	}
	if(m > 1) v.push_back(m);
	int n = v.size();
	vec.resize(1<<n);
	vec[0] = 1; mu[1] = 1;
	for(int i = 1; i < 1<<n; ++i) {
		vec[i] = vec[i^(i&-i)] * v[lb[i & -i]];
		mu[vec[i]] = -mu[vec[i^(i&-i)]];
	}
}

bool h[maxn];

int main() {
	for(int i = 0; i <= 19; ++i) 
		lb[1<<i]=i;
	int n, m, x;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		init(a[i]);
	}
	long long ans = 0;
	for(int k = 0; k < m; ++k) {
		scanf("%d", &x);
		if (h[x]) 
			for(size_t i = 0; i < a[x].size(); ++i) 
				--s[a[x][i]], ans -= s[a[x][i]] * mu[a[x][i]];
		else 
			for(size_t i = 0; i < a[x].size(); ++i) 
				ans += s[a[x][i]] * mu[a[x][i]], s[a[x][i]]++;
		h[x] = !h[x];
		cout << ans << endl;
	}
}