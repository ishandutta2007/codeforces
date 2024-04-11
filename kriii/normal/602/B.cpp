#include <stdio.h>
#include <deque>
using namespace std;

deque<pair<int, int> > mn,mx;
int N;

int main()
{
	scanf ("%d",&N);
	int ans = 1, low = -1;
	for (int i=0;i<N;i++){
		int x; scanf ("%d",&x);
		while (!mn.empty() && mn.back().first > x) mn.pop_back();
		mn.push_back(make_pair(x,i));
		while (!mx.empty() && mx.back().first < x) mx.pop_back();
		mx.push_back(make_pair(x,i));
		while (mx.front().first - mn.front().first >= 2){
			low++;
			while (mx.front().second <= low) mx.pop_front();
			while (mn.front().second <= low) mn.pop_front();
		}
		int len = i - low;
		if (ans < len)
			ans = len;
	}
	printf ("%d\n",ans);

	return 0;
}