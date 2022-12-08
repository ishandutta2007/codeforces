#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

priority_queue<pair<int, int> > Q,R;

int N,a[200200],t[200200]; long long T,S;
vector<int> g[200200];

int main()
{
	scanf ("%d %lld",&N,&T);
	for (int i=1;i<=N;i++){
		scanf ("%d %d",&a[i],&t[i]);
		g[a[i]].push_back(i);
	}

	for (int p=N;p>=1;p--){
		for (auto &i : g[p]) R.push({-t[i],i});

		while (!Q.empty() && !R.empty() && Q.top().first > -R.top().first){
			auto q = Q.top(); Q.pop(); q.first = -q.first;
			auto r = R.top(); R.pop(); r.first = -r.first;
			S += q.first;
			S += r.first;
			Q.push(r);
			R.push(q);
		}
		while (Q.size() < p && !R.empty()){
			auto r = R.top(); R.pop(); r.first = -r.first;
			S += r.first;
			Q.push(r);
		}
		while (Q.size() > p){
			auto q = Q.top(); Q.pop(); q.first = -q.first;
			S += q.first;
			R.push(q);
		}
		if (Q.size() == p && S <= T){
			printf ("%d\n%d\n",p,p);

			while (!Q.empty()){
				printf ("%d ",Q.top().second);
				Q.pop();
			}
			return 0;
		}
	}
	printf ("0\n0\n\n");

	return 0;
}