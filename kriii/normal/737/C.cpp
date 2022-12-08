#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N,S;

int main()
{
	scanf ("%d %d",&N,&S);
	int ans = 0, free = 0;
	vector<int> u;
	for (int i=1;i<=N;i++){
		int x; scanf ("%d",&x);
		if (x == 0){
			if (i != S) free++, ans++;
		}
		else{
			if (i == S) ans++;
			else u.push_back(x);
		}
	}
	u.push_back(0);
	sort(u.begin(),u.end());

	int need = 0, now = u.size() - 1;
	for (int i=1;i<u.size();i++){
		if (abs(u[i]-u[i-1]) > 1){
			need += abs(u[i]-u[i-1]) - 1;
		}

		int res = free + u.size() - i - 1;
		if (need <= res){
			if (now > u.size() - i - 1)
				now = u.size() - i - 1;
		}
	}

	printf ("%d\n",ans+now);

	return 0;
}