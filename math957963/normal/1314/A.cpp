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
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200010


int main() {
	vector<pair<long long, long long> >a;
	priority_queue<long long>pq;
	long long b[N];
	long long n, k, kk;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%I64d", &n);
	f(i, n) {
		scanf("%I64d", &b[i]);
	}
	f(i, n) {
		scanf("%I64d", &x);
		a.push_back(make_pair(b[i], x));
	}
	sort(a.begin(), a.end());
	k = 0;
	x = 0;
	s = 0;
	ans = 0;
	while(k<n) {
		kk = a[k].first;
		while (a[k].first == kk) {
			x++;
			s += a[k].second;
			pq.push(a[k].second);
			k++;
          if(k>=n)break;
		}
		while (x > 1) {
			y = pq.top();
			pq.pop();
			s -= y;
			ans += s;
			x--;
			kk++;
          if(k<n){
			while (a[k].first == kk) {
				x++;
				s += a[k].second;
				pq.push(a[k].second);
				k++;
              if(k>=n)break;
			}
          }
		}
		pq.pop();
		x--;
		s = 0;
	}
	printf("%I64d\n", ans);


	return 0;
}