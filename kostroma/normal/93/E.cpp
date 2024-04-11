#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <memory.h>
#include <algorithm>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long double ld;

void solve();
int main()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	int t=1;
	while (t--)
		solve();
	return 0;
}

//#define int li

int k;
li a[200];

li answers[100500][111];

li solving (long long n, int pos)
{
	if (n==0)
		return 0;
	if (pos==-1)
		return 0;
	if (pos==0)
		return n/a[pos];
	if (n<100500 && answers[n][pos]!=-1)
		return answers[n][pos];
	li ans=0;
	for (int i=0; i<=pos; i++)
		ans+=(n/a[i])-solving(n/a[i], i-1);
	if (n<100500)
		answers[n][pos]=ans;
	return ans;
}

void solve()
{
	long long n;
	scanf ("%I64d%d", &n, &k);
	for (int i=0; i<k; i++)
		scanf ("%I64d", &a[i]);
	sort (a, a+k);
	memset (answers, -1, sizeof answers);
	li z=solving(n, k-1);
	cout<<n-z;
}