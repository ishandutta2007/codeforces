#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007

int main(){
	string s;
	cin >> s;
	int n = (int)s.size();
	ll ans = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(s[i]=='Q'&&s[j]=='A'&&s[k]=='Q'){
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}