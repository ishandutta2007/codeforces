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

int main(){
    int n;
    cin >> n;
    vector<pair<int,int> >v(n);
    for(int i=0;i<n;i++){
        vector<int>a(4);
        int s=0;
        for(int j=0;j<4;j++){
            cin >> a[j];
            s += a[j];
        }
        v[i] = MP(s,-i);
    }
    sort(v.begin(),v.end(),greater<pair<int,int> >());
    for(int i=0;i<n;i++){
        if(v[i].second==0){
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;
}