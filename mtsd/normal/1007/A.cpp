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
    scanf("%d",&n);
    vector<int> a(n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a.begin(),a.end(),greater<int>());
    int x = 0;
    int y = 1;
    int cnt = 0;
    while(y<n){
        if(a[x]>a[y]){
            x++;
            y++;
            cnt++;
        }else{
            y++;
        }
    }
    cout << cnt << endl;
    return 0;
}