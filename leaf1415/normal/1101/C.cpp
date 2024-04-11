#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n;
llint l[100005], r[100005];
vector<P> vec;

int main(void)
{
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 0; i < n; i++) cin >> l[i] >> r[i];
		vec.clear();
		for(int i = 0; i < n; i++){
			vec.push_back(make_pair(l[i], 0));
			vec.push_back(make_pair(r[i], 1));
		}
		sort(vec.begin(), vec.end());
		
		int cnt = 0, p;
		for(int i = 0; i < vec.size(); i++){
			if(vec[i].second == 0) cnt++;
			else cnt--;
			if(cnt == 0){
				if(i == (int)vec.size()-1){
					cout << -1 << endl;
					goto end;
				}
				p = vec[i].first;
				break;
			}
		}
		
		for(int i = 0; i < n; i++){
			if(r[i] <= p) cout << 1 << " ";
			else cout << 2 << " ";
		}
		cout << endl;
		end:;
	}
	return 0;
}