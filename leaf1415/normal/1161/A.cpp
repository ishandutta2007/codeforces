#include <iostream>
#include <set>
#include <utility>
#define llint long long

using namespace std;

llint n, k;
llint x[100005];
set<pair<int, int> > S;
set<int> T;

int main(void)
{
	cin >> n >> k;
	for(int i = 1; i <= k; i++) cin >> x[i];
	
	for(int i = 1; i <= k; i++){
		S.insert(make_pair(x[i], x[i]));
		if(T.count(x[i]-1)) S.insert(make_pair(x[i]-1, x[i]));
		if(T.count(x[i]+1)) S.insert(make_pair(x[i]+1, x[i]));
		T.insert(x[i]);
	}
	cout << n+2*(n-1)- S.size() << endl;
	
	return 0;
}