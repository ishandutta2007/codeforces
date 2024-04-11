/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int maxN = 1000 * 1000 + 10;

int n,m;
int pos[maxN],a[maxN],b[maxN],mp[maxN];

int mod (int x, int m){
	while (x>=m) x-=m;
	return x;
}

bool range (const int &l, const int &h, const int &x){
	return x>=l && x<=h;
}

int main(){
	
	scanf ("%d%d" , &n, &m);
	memset(mp,-1,sizeof mp);
	for (int i=0; i<n; i++) scanf("%d" , &a[i]);
	for (int i=0; i<m; i++) { scanf("%d" , &b[i]); mp[b[i]] = i; }

	for (int i=0; i<n; i++)
		pos[i] = mp[a[i]];

	int poi=-1 , ans = 0;

	for (int i=0; i<n && ans<min(n,m); i++){
		
		if (pos[i]==-1){
			poi = -1;
			continue;
		}

		ans = max(1,ans);

		if (poi==-1)
			poi=i;

		int lo1 = pos[i]+1 , hi1 = m-1;
		int lo2 = 0 , hi2 = pos[i]-1;

		if (poi!=i){
			if (range(lo1,hi1,pos[poi])) lo1 = pos[poi] + 1;
			else if (range(lo2,hi2,pos[poi])) { lo2 = pos[poi] + 1; hi1=-1,lo1=0; }
		}

		while (true){
			
			poi = (poi + 1) % n;

			if (poi==i){
				ans = n;
				break;
			}
			
			bool f = false;

			if (range(lo1,hi1,pos[poi])) { lo1 = pos[poi] + 1; f = true; }
			else if (range(lo2,hi2,pos[poi])) { lo2 = pos[poi] + 1; f = true; hi1=-1; lo1=0; }

			if (!f || pos[poi]==-1){
				poi = (poi-1+n)%n;
				break;
			}

		}

		if (poi<i)
			ans = max(ans , (n-i) + poi + 1);
		else if (poi>i)
			ans = max(ans , (poi-i+1));

		if (poi==i)
			poi = -1;
	}

	printf ("%d\n" , ans);

	return 0;
}