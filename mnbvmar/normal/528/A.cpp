#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int W, H, N;

void input(){
	scanf("%d%d%d", &W, &H, &N);
}

int main(){
	input();

	multiset<int> widths={W}, heights={H};
	set<int> breaksVer={0,W}, breaksHor={0,H};

	for(int query = 1; query <= N; query++){
		char str[3];
		int x;

		scanf("%s%d", str, &x);

		if(str[0] == 'H'){
			int prevCut = *(prev(breaksHor.upper_bound(x))),
				nextCut = *(breaksHor.lower_bound(x));

			heights.erase(heights.find(nextCut-prevCut));
			heights.insert(x-prevCut);
			heights.insert(nextCut-x);
			breaksHor.insert(x);
		} else {
			int prevCut = *(prev(breaksVer.upper_bound(x))),
				nextCut = *(breaksVer.lower_bound(x));

			widths.erase(widths.find(nextCut-prevCut));
			widths.insert(x-prevCut);
			widths.insert(nextCut-x);
			breaksVer.insert(x);
		}

		int maxW = *widths.rbegin(),
			maxH = *heights.rbegin();

		cout << (LL)maxW * maxH << "\n";
	}
}