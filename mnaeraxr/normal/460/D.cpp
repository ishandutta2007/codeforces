#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int64> vi;

void ans(vi v){
	int64 x = 0;
	for (auto t : v) x ^= t;
	cout << x << endl;
	cout << v.size() << endl;
	for (auto t : v)
		cout << t << " ";
	cout << endl;
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 l, r, k;
	cin >> l >> r >> k;
	
	if (k >= 5){
		if (l & 1) ++l;
		ans({l, l + 1, l + 2, l + 3});
	}
	else if (k == 1)
		ans({l});
	else if (k == 2){
		if (l % 2 == 0)
			ans({l, l + 1});
		else{
			if (l + 2 <= r) ans({l + 1, l + 2});
			else{
				if (l < (l ^ (l + 1))) ans({l});
				else ans({l, l + 1});
			}
		}
	}
	else if (k == 4){
		if (l % 2 == 0) ans({l, l + 1, l + 2, l + 3});
		if (l + 4 <= r) ans({l + 1, l + 2, l + 3, l + 4});
		
		int64 x = 1;
		vi t = {l + 1, l + 2};

		for (int i = 1; i < (1 << 4); ++i){
			int64 tx = 0;
			vi cc = {};
			for (int j = 0; j < 4; ++j)
				if (i & (1 << j)){
					tx ^= l + j;
					cc.push_back(l + j);
				}
			if (tx == 0){
				t = cc;
				break;
			}
		}

		ans(t);
	}
	else{
		int64 v = 2;
		for(;v + v / 2 <= r; v *= 2)
			if (v - 1 >= l)
				ans({v - 1, v + v / 2 - 1, v + v / 2});

		if (l & 1) ++l;
		ans({l, l + 1});
	}

	return 0;
}