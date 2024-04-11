#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n, m;
llint a[105];
llint p[105];
vector<P> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> m;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= m; i++) cin >> p[i];
		sort(p+1, p+m+1);
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(a[p[j]] > a[p[j]+1]) swap(a[p[j]], a[p[j]+1]);
			}
		}
		
		for(int i = 1; i < n; i++){
			if(a[i] > a[i+1]){
				cout << "NO" << endl;
				goto end;
			}
		}
		cout<< "YES" << endl;
		end:;
	}
	flush(cout);
	
	return 0;
}