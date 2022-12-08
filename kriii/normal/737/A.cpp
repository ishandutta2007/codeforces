#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N,K,S,T;

int main()
{
	vector<int> p,l;
	scanf ("%d %d %d %d",&N,&K,&S,&T);

	vector<pair<int, int> > car;
	for (int i=0;i<N;i++){
		int c,g;
		scanf ("%d %d",&c,&g);
		car.push_back({g,c});
	}
	sort(car.begin(),car.end());

	for (int i=0;i<K;i++){
		int x; scanf ("%d",&x);
		p.push_back(x);
	}
	p.push_back(0);
	p.push_back(S);
	sort(p.begin(),p.end());

	for (int i=1;i<p.size();i++) l.push_back(p[i]-p[i-1]);
	sort(l.begin(),l.end());

	long long sum = 0;

	int i = 0;
	long long fullt = 0, subc = 0, subt = 0;
	for (int x : l){
		subc++; subt += x * 3ll;
	}

	int ans = 0x7fffffff;
	for (auto p : car){
		if (p.first < l.back()) continue;
		while (i < l.size() && l[i] * 2 < p.first){
			subc--; subt -= l[i] * 3ll; fullt += l[i];
			i++;
		}
		long long now = subt - subc * p.first + fullt;
		if (now <= T){
			if (ans > p.second)
				ans = p.second;
		}
	}

	if (ans == 0x7fffffff)
		ans = -1;
	printf ("%d\n",ans);

	return 0;
}