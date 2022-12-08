#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> d;
int mob[1000001];

int go(int l, int r)
{
	int res = 0;
	for (int x : d) if (mob[x]){
		res += mob[x] * (r / x - (l + x - 1) / x + 1);
	}
	return res;
}

int main()
{
	mob[1] = 1;
	for (int i=1;i<=1000000;i++){
		for (int j=i*2;j<=1000000;j+=i) mob[j] -= mob[i];
	}

	int T; scanf ("%d",&T); while (T--){
		int x,p,k; scanf ("%d %d %d",&x,&p,&k);

		d.clear();
		for (int i=1;i*i<=p;i++) if (p % i == 0){
			d.push_back(i);
			if (i * i != p) d.push_back(p / i);
		}

		int l = x + 1, r = 100000000, a = 100000000;
		while (l <= r){
			int m = (l + r) / 2;
			if (go(x+1,m) >= k){
				r = m - 1; a = m;
			}
			else l = m + 1;
		}
		printf ("%d\n",a);
	}

	return 0;
}