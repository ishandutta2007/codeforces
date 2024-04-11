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
#define N 200000


int main() {
	vector<long long>a;
	vector<long long>d;
	vector<long long>q;
	map<long long, long long> m;
	long long s;
	long long k;
	long long b;
	long long ans[N];
	long long n;
	long long x, y, z;
	scanf("%I64d", &n);
	f(i, n) {
		scanf("%I64d", &x);
		a.push_back(x);
	}
	scanf("%I64d", &z);
	f(i, z) {
		scanf("%I64d %I64d", &x,&y);
		q.push_back(y-x+1);
		ans[i] = y-x+1;
	}
	sort(a.begin(), a.end());
	f(i, n-1) {
		d.push_back(a[i + 1] - a[i]);
	}
	sort(d.begin(), d.end());
	sort(q.begin(), q.end());
	s = 0;
	k = n;
	b = 0;
	f(qq, q.size()) {
		while (b < d.size()) {
			if (d[b] < q[qq]) {
				s += d[b];
				k--;
				b++;
			}
			else break;
		}
		x = k * q[qq];
		x += s;
		m[q[qq]] = x;
	}
	f(i, z){
printf("%I64d", m[ans[i]]);
     if(i<(z-1))printf(" ");
      else printf("\n");
      
    }


	return 0;
}