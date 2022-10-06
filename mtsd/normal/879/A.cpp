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

long long  mod = 1000000007;

int main(){
	int n;
	cin >> n;
	VI s(n),d(n);
	for(int i=0;i<n;i++){
		cin >> s[i] >> d[i];
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		if(ans<s[i]){
			ans = s[i];
		}else{
			int x = ans+1 -s[i];
			int y = (int)ceil((double)x/(double)d[i]);
			ans = s[i] + d[i]*y;
		}
	}
	cout << ans << endl;
	return 0;
}