#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

int A, B, Q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> A >> B >> Q;
	while (Q--){
		int l, t, k;
		cin >> l >> t >> k;
		lld lth = A + (lld)(l-1)*B;
		int s = l, e = t+1, ans = -1;
		while (s <= e){
			int m = (s+e)>>1;
			lld mth = A + (lld)(m-1)*B;
			if (mth > t) e = m-1;
			else if ((lth+mth)*(m-l+1)/2 > (lld)k*t) e = m-1;
			else s = m+1, ans = m;
		}
		cout << ans << endl;
	}
}