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
    vector<int>a(4*n+1),b(4*n+1);
    rep(i,4*n+1){
        cin >> a[i] >> b[i];
    }
    
    rep(i,51){
        rep(j,51){
            if(i<j)continue;
            rep(k,51){
                rep(l,51){
                    if(k<l)continue;
                    int c = 0;
                    int s,t;
                    rep(x,4*n+1){
                        if((a[x]==i||a[x]==j)&&(b[x]<=k&&b[x]>=l)){
                            c++;
                        }else if((a[x]<=i&&a[x]>=j)&&(b[x]==k||b[x]==l)){
                            c++;
                        }else{
                            s = a[x];
                            t = b[x];
                        }
                    }
                    if(c==4*n){
                        //cout << i << " " << j << " " << k << " " << l << endl;
                        cout << s << " " << t << endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}