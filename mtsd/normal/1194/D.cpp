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
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    int q;
    cin >> q;
    rep(zz,q){
        int n,m;
        cin >> n >> m;
        if(m%3!=0){
            if(n%3==0){
                cout << "Bob" << endl;
            }else{
                cout << "Alice" << endl;
            }
        }else{
            if((n%(m+1)!=m)&&(n%(m+1))%3==0){
                cout << "Bob" << endl;
            }else{
                cout << "Alice" << endl;
            }
        }
    }


    return 0;
}