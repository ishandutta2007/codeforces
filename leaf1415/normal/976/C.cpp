#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int, int> P;

int n;
vector< pair<P, int> > vec;

int main(void)
{
	cin >> n;
	int l, r;
	for(int i = 1; i <= n; i++){
		cin >> l >> r;
		vec.push_back( make_pair(make_pair(l, -r), i) );
	}
	sort(vec.begin(), vec.end());
	
	for(int i = 0; i < vec.size()-1; i++){
		if(vec[i].first.second <= vec[i+1].first.second){
			cout << vec[i+1].second << " " << vec[i].second << endl;
			return 0;
		}
	}
	
	cout << -1 << " " << -1 << endl;
	return 0;
}