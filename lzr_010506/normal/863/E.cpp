    #include <cstdio>
    #include <iostream>
    #include <vector>
    #include <set>
    #include <map>
    #include <cmath>
    #include <string>
    #include <cstring>
    #include <sstream>
    #include <algorithm>
    using namespace std;
     
    typedef pair <int, int> ii;
    typedef pair <ii, int> iii;
     
    const int Maxn = 200005;
     
    int n;
    iii seq[Maxn];
     
    bool Less(const iii &a, const iii &b)
    {
    	if (a.first.first != b.first.first) return a.first.first < b.first.first;
    	if (a.first.second != b.first.second) return a.first.second > b.first.second;
    	return a.second < b.second;
    }
     
    int main()
    {
    	scanf("%d", &n);
    	for (int i = 0; i < n; i++) {
    		scanf("%d %d", &seq[i].first.first, &seq[i].first.second);
    		seq[i].second = i + 1;
    	}
    	sort(seq, seq + n, Less);
    	int lst = -1;
    	for (int i = 0; i < n; i++)
    		if (seq[i].first.second <= lst) { printf("%d\n", seq[i].second); return 0; }
    		else lst = seq[i].first.second;
    	for (int i = 1; i + 1 < n; i++) {
    		int lef = seq[i - 1].first.second + 1, rig = seq[i + 1].first.first;
    		//lef = max(lef, seq[i].first.first); rig = min(rig, seq[i].first.second);
    		if (lef >= rig) { printf("%d\n", seq[i].second); return 0; }
    	}
    	printf("-1\n");
    	return 0;
    }