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
	set<int> st;
	int n;
	cin >> n;
	vector<int>a(n),b(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
		st.insert(a[i]);
	}
	for(int i=0;i<n;i++){
		cin >> b[i];
		st.insert(b[i]);
	}
	ll ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(st.count(a[i]^b[j])){
				ans++;
			}
		}
	}
	if(ans%2==0){
		cout << "Karen" << endl;
	}else{
		cout << "Koyomi" << endl;
	}
	return 0;
}