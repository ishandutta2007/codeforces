#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

long long x;
int n, d, b[100001], a[100001];
map<int, int> events;
vector<int> c;

long long getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

inline void initAB() {
    for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main(){
	scanf("%d%d%I64d", &n, &d, &x);
	initAB();
	for (int i = n; i; --i) a[i] = a[i - 1], b[i] = b[i - 1];
	events.clear(); c.clear();
	for (int i = 1; i <= n; i++)
	{
		events.insert(make_pair(a[i], i));
		if (b[i]) c.push_back(i);
		int ans = 0;
		if (c.size() * c.size() <= i)
			for (int j = 0; j < c.size(); j++) ans = max(ans, a[i + 1 - c[j]]);
		else 
		{
			map<int, int>::iterator itr = events.end();
			for (; itr != events.begin();) 
			{
				--itr;
				if (b[i + 1 - (itr->second)]) 
				{
					ans = itr->first;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
}