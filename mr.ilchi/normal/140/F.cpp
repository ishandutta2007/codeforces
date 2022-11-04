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
typedef complex<int> point;
typedef long double ldb;

const int MAXN = 200000+10;

int n,k;
point a[MAXN];
vector <point> cent;

bool cmp (const point &A, const point &B) { return (A.real()!=B.real()) ? (A.real()<B.real()) : (A.imag()<B.imag()); }

int main(){
	cin >> n >> k; 
	for (int i=1; i<=n; i++)
		cin >> a[i].real() >> a[i].imag();
	if (n<=k){
		cout << -1 << endl;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1; i<=n; i++) if (abs(n-2*i+1)<=k)
		cent.push_back(a[i]*2);
	for (int i=1; i<=min(n,k+1); i++)
		for (int j=n; i<j && (n-j+i-1)<=k; j--)
			cent.push_back(a[i]+a[j]);
	sort(cent.begin(),cent.end(),cmp);
	vector <point> ans;
	for (int i=0; i<(int)cent.size(); i++) if (i==0 || cent[i]!=cent[i-1]){
		int bad=0,poi=n;
		for (int j=1; j<=n; j++){
			while (poi>1 && cmp(cent[i],a[j]+a[poi])) 
				poi--;
			if (a[j]+a[poi]!=cent[i])
				bad++;
		}
		if (bad<=k)
			ans.push_back(cent[i]);
	}
	cout << ans.size() << endl;
	for (int i=0; i<(int)ans.size(); i++)
		cout << fixed << setprecision(1) << ans[i].real()/2.0 << ' ' << ans[i].imag()/2.0 << endl;
	return 0;
}