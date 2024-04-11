#include<bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5,K = 3e6 + 5;
int n,k,a[N],cnt,cnt2,b[N];
char s[N];
vector<int> v;
signed main() {
	cin >> n >> k >> s+1;
	for(int i = 1;i <= n;++i)
		if(s[i] == 'L') a[i] = b[i] = 1;
	for(int i = 1;i <= n;++i)
		for(int j = 1;j < n;++j)
			if(b[j] < b[j+1]) {
				++cnt2;
				swap(b[j],b[j+1]);
			}
	for(int i = 1;i <= n;++i)
		b[i] = a[i];
	while(1) {
		int ok = 1;
		for(int j = 1;j < n;++j)
			if(b[j] == 0 && b[j+1] == 1) {
				ok = 0;
				swap(b[j],b[j+1]);
				++j;
			}
		if(ok) break;
		++cnt;
	}
	if(cnt <= k && k <= cnt2) {
		int rest = k - cnt;
		for(int i = 1;i <= cnt;++i) {
			v.clear();
			for(int j = 1;j < n;++j)
				if(a[j] == 0 && a[j+1] == 1)
					v.push_back(j),++j;
			while(rest && v.size() > 1) {
				--rest;
				printf("1 %d\n",v[v.size()-1]);
				swap(a[v[v.size()-1]],a[v[v.size()-1]+1]);
				v.pop_back();
			}
			printf("%d",(int)v.size());
			for(int j = 0;j < v.size();++j)
				printf(" %d",v[j]),swap(a[v[j]],a[v[j]+1]);
			puts("");
		}
	}
	else puts("-1");
	return 0;
}