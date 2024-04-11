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
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

long long  mod = 1000000007;

char x[]={'a','i','u','e','o','1','3','5','7','9'};

int main(){
	string s;
	cin >> s;
	int cnt=0;
	rep(i,s.size()){
		rep(j,10){
			if(s[i]==x[j]){
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}