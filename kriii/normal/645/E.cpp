#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int mod = 1000000007;
char S[1000005]; int k; long long c[26];
int ind[26];

int main()
{
	int n,k;
	scanf ("%d %d %s",&n,&k,S);
	long long s = 1;
	for (int i=0;i<k;i++) ind[i] = -1;
	for (int i=0;S[i];i++){
		int x = S[i] - 'a';
		ind[x] = i;
		long long u = c[x];
		c[x] = s;
		s = (2 * s - u + mod) % mod;
	}

	vector<pair<int, int> > a;
	for (int i=0;i<k;i++) a.push_back(make_pair(ind[i],i));
	sort(a.begin(),a.end());
	for (int i=0;i<n;i++){
		int x = a[i%k].second;
		long long u = c[x];
		c[x] = s;
		s = (2 * s - u + mod) % mod;
	}

	printf ("%lld\n",s);

	return 0;
}