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
    int n,k,d;
    cin >> n >> k >> d;
    vector<bool> flag(n);
    vector<int> a(n);
    vector<int> v(n);
    flag[0] = 1;
    rep(i,n)scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    a[0] = v[0];
    bool ng = 0;
    for(int i=1;i<n;i++){
        if(i<k){
            //flag[i] = 0;
            a[i] = a[i-1];
            if(v[i]-a[i]>d){
                ng = 1;
                break;
            }
        }else if(i>n-k){
            //flag[i] = 0;
            a[i] = a[i-1];
            if(v[i]-a[i]>d){
                ng = 1;
                break;
            }
        }else{
            if(v[i-1]<=a[i-k]+d){
                //flag[i] = 1;
                a[i] = v[i];
            }else{
                a[i] = a[i-1];
                if(v[i]>a[i]+d){
                    ng = 1;
                    break;
                }
            }
        }

    }
    if(ng){
        cout << "NO"<< endl;
    }else{
        cout << "YES" << endl;
    }
    return 0;
}