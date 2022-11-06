#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main() {
	vector<pair<long long, long long> >pp;
	vector<pair<long long, long long> >p;
	stack<int>a;
	int n, k;
	long long x, y,xx,yy,z,zz;
	long long nx, ny;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n) {
		scanf("%I64d %I64d", &x,&y);
		pp.push_back(make_pair(-x,  (x*x)-y));
	}
	sort(pp.begin(),pp.end());

	f(i, n) {
		if (i == 0)p.push_back(make_pair(pp[i].first, pp[i].second));
		else if(pp[i-1].first!= pp[i].first)p.push_back(make_pair(pp[i].first, pp[i].second));
	}
	ans = 0;
	nx = -1000000000;
	ny = 1;
	k = 0;
	a.push(0);
	for (int i = 1; i < p.size();i++) {
			while (a.size() > 1) {
				z = a.top();
				a.pop();
				zz = a.top();
				a.push(z);
				x = p[i].second - p[z].second;
				y = p[i].first - p[z].first;
				xx = p[z].second - p[zz].second;
				yy = p[z].first - p[zz].first;
				if (x*yy > y*xx) {
					a.push(i);
					nx = x;
					ny = y;
					ans++;
					k = i;
					break;
				}
				else if (x*yy == y * xx) {
					a.pop();
					a.push(i);
					k = i;
					nx = x;
					ny = y;
					break;
				}
				else {
					a.pop();
					ans--;
				}
			}
			if (a.size() == 1) {
				ans++;
				a.push(i);
				k = i;
				z = a.top();
				nx = p[i].second - p[z].second;
				ny = p[i].first - p[z].first;
			}
	}

	printf("%d\n", ans);


	return 0;
}