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
    int n,k,m,t;
    cin >> n >> k >> m >> t;
    int len = n;
    int id = k;
    rep(zz,t){
        int a,b;
        cin >> a >> b;
        if(a==0){
            if(b>=id){
                len = b;
            }else{
                len -=b;
                id -=b;
            }
        }else{
            len++;
            if(b<=id){
                id++;
            }
        }
        cout << len << " " << id << endl;
    }
    
    return 0;
}