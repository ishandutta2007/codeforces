#include <stdio.h>
#include <vector>
using namespace std;

long long P; int K;

int main()
{
	scanf ("%lld %d",&P,&K);
	vector<int> ans;
	while (P){
		int R = (P % K + K) % K;
		ans.push_back(R);
		P -= R;
		P /= K;
		P = -P;
	}
	printf ("%d\n",ans.size());
	for (auto &x : ans) printf ("%d ",x);
	return 0;
}