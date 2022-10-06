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
    if((n/2)%2!=0){
        cout << "! -1" << endl;
        return 0;
    }
    int x,y;
    cout << "? 1" << endl;
    cin >> x;
    cout << "? " << 1+n/2 << endl;
    cin >> y;
    if(x==y){
        cout << "! 1" << endl;
        return 0;
    }
    if(x-y>0){
        int ok = 1;
        int ng = 1+n/2;
        while(1){
            int a,b;
            int mid = (ok+ng)/2;
            cout << "? " << mid << endl;
            cin >> a;
            cout << "? " << mid+n/2 << endl;
            cin >> b;
            if(a-b>0){
                ok = mid;
            }else if(a-b<0){
                ng = mid;
            }else{
                cout << "! " << mid << endl;
                return 0;
            }
        }
    }else{
        int ok = 1;
        int ng = 1+n/2;
        while(1){
            int a,b;
            int mid = (ok+ng)/2;
            cout << "? " << mid << endl;
            cin >> a;
            cout << "? " << mid+n/2 << endl;
            cin >> b;
            if(a-b>0){
                ng = mid;
            }else if(a-b<0){
                ok = mid;
            }else{
                cout << "! " << mid << endl;
                return 0;
            }
        }
    }
    return 0;
}