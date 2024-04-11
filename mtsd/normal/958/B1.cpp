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

int main(){
    int n;
    cin >> n;
    vector<int> s(n+1);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        s[a]++;
        s[b]++;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(s[i]==1){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}