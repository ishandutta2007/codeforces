#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> X[200200];
int N;

int main()
{
	scanf ("%d",&N);
	int mx = 0;
	for (int i=0;i<N;i++){
		int m; scanf ("%d",&m); while (m--){
			int x; scanf ("%d",&x); X[i].push_back(x);
		}
		sort(X[i].begin(),X[i].end());
		mx = max(mx,X[i].back());
	}

	long long ans = 0;
	for (int i=0;i<N;i++){
		long long up = mx - X[i].back();
		ans += up * X[i].size();
	}
	printf ("%lld\n",ans);

	return 0;
}