#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int> > S[200050];

int main()
{
	int N,X;
	scanf ("%d %d",&N,&X);
	for (int i=0;i<N;i++){
		int l,r,x;
		scanf ("%d %d %d",&l,&r,&x);
		S[r-l+1].push_back({l,x});
	}
	for (int i=0;i<=X;i++) sort(S[i].begin(),S[i].end());

	int ans = 0x7fffffff;
	for (int d=1;d<X;d++){
		auto &u = S[d], &v = S[X-d];
		int mn = 0x7fffffff;
		for (int i=0,j=0;i<v.size();i++){
			while (j<u.size() && u[j].first + d - 1 < v[i].first){
				if (mn > u[j].second)
					mn = u[j].second;
				j++;
			}
			if (mn != 0x7fffffff){
				int s = mn + v[i].second;
				if (ans > s)
					ans = s;
			}
		}
	}
	if (ans == 0x7fffffff) ans = -1;
	printf ("%d\n",ans);

	return 0;
}