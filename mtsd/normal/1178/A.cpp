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
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n)cin >> a[i];
    int sm = 0;
    rep(i,n){
        sm += a[i];
    }
    vector<int> p;
    int smm = a[0];
    p.push_back(1);
    for(int i=1;i<n;i++){
        if(a[0]>=2*a[i]){
            smm += a[i]; 
            p.push_back(i+1);
        }
    }
    if(smm*2>sm){
        cout << p.size() << endl;
        rep(i,p.size()){
            cout << p[i];
            if(i!=p.size()-1){
                cout << " ";
            }
            
        }
        cout << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}