

    #include <bits/stdc++.h>
    using namespace std;
    typedef long long LL;
    #define read(a) scanf("%d", &a)
     
    int n;
     
    priority_queue < pair<int, int> > q;
    set <int> vis;
     
    int main() {
    	read(n);
    	int a;
    	read(a);
    	int su = 0;
    	su += a;
    	for (int i =2; i <= n; i++) {
    		int x;
    		read(x);
    		su += x;
    		q.push({-x, i});
    	}
    	vis.insert(1);
    	int sa = a;
    	while (!q.empty()) {
    		auto x = q.top(); q.pop();
    		int v = -x.first, y = x.second;
    		if (sa >= 2 * v) a += v, vis.insert(y);
    		else break;
    	}
    	if (a > su / 2) {
    		printf("%d\n", (int)vis.size());
    		for (auto v : vis) {
    			printf("%d ", v);
    		}
    	}
    	else puts("0");
     
    }