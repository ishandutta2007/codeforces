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
    int n,k,m,l;
    scanf("%d %d %d",&n,&k,&l);
    m = n*k;
    vector<ll> a(m);
    rep(i,m)scanf("%lld",&a[i]);
    sort(a.begin(),a.end());
    bool flag = 0;
    ll ans = 0;
    int p = 0;
    rep(i,m){
        if(a[i]>a[0]+l){
            p++;
        }
    }
    if(p>m-n){
        cout << 0 << endl;
    }else{
        if(n==1){
            cout << a[0] << endl;
        }else if(k==1){
            rep(i,m){
                ans += a[i];
            }
            cout <<  ans << endl;
        }else{
            int z=0;
            bool ffflag = 0;
            rep(i,m){
                if(a[i]>a[0]+l){
                    z = i-1;
                    ffflag = 1;
                    break;
                }
            }
            if(!ffflag){
                z = m-1;
            }
            vector<ll> b(m);
            int x = m-1;
            int ind = m-1;
            while(1){
                if(x==z)break;
                if(ind%k==0){
                    ind--;
                    b[ind] = a[x];
                }else{
                    b[ind] = a[x];
                }
                ind--;
                x--;
            }
            x = 0;
            ind = 0;
            while(1){
                if(x>z)break;
                if(b[ind]!=0){
                    ind++;
                }else{
                    b[ind] = a[x];
                    x++;
                    ind++;
                }
            }
            rep(i,n){
                ans += b[i*k];
            }
            cout << ans << endl;
        }
    }
    return 0;
}