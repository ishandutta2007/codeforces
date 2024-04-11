#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200000

int main(){
	vector<pair<int,int> >a;
	vector<pair<int, int> >ans;
	set<pair<int, int> >s;
	int x, y, z;
	f(i, 3){
		scanf("%d %d", &x, &y);
		a.push_back(make_pair(x, y));
	}
	sort(a.begin(), a.end());
	for (int i = a[0].first; i <= a[1].first; i++){
		if (s.count(make_pair(i, a[0].second)) == 0){
			s.insert(make_pair(i, a[0].second));
			ans.push_back(make_pair(i, a[0].second));
		}
	}
	for (int i = a[1].first; i <= a[2].first; i++){
		if (s.count(make_pair(i, a[2].second)) == 0){
			s.insert(make_pair(i, a[2].second));
			ans.push_back(make_pair(i, a[2].second));
		}
	}
	if (a[0].second <= a[1].second){
		for (int i = a[0].second; i <= a[1].second; i++){
			if (s.count(make_pair(a[1].first, i)) == 0){
				s.insert(make_pair(a[1].first, i));
				ans.push_back(make_pair(a[1].first, i));
			}
		}
	}
	else{
		for (int i = a[1].second; i <= a[0].second; i++){
			if (s.count(make_pair(a[1].first, i)) == 0){
				s.insert(make_pair(a[1].first, i));
				ans.push_back(make_pair(a[1].first, i));
			}
		}
	}
	if (a[2].second <= a[1].second){
		for (int i = a[2].second; i <= a[1].second; i++){
			if (s.count(make_pair(a[1].first, i)) == 0){
				s.insert(make_pair(a[1].first, i));
				ans.push_back(make_pair(a[1].first, i));
			}
		}
	}
	else{
		for (int i = a[1].second; i <= a[2].second; i++){
			if (s.count(make_pair(a[1].first, i)) == 0){
				s.insert(make_pair(a[1].first, i));
				ans.push_back(make_pair(a[1].first, i));
			}
		}
	}


	printf("%d\n", ans.size());
	f(i, ans.size())printf("%d %d\n", ans[i].first, ans[i].second);


	return 0;
}