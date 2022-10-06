#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int ans = 0;
    int tmp = 0;
    tmp = min(a,b-1);
    tmp = min(tmp,c-2);
    ans = tmp*3+3;
    cout << ans << endl;
    return 0;
}