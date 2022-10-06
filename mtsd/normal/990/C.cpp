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
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string>v(n);
    rep(i,n){
        cin >> v[i];
    }
    vector<int>l(300001);
    vector<int>r(300001);
    for(int i=0;i<n;i++){
        if(v[i][0]=='('){
            int a = 0;
            bool flag = 0;
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]=='('){
                    a++;
                }else{
                    a--;
                }
                if(a<0){
                    flag =1;
                    break;
                }
            }
            if(!flag){
                l[a]++;
            }
        }
        int x = (int)v[i].size();
        if(v[i][x-1]==')'){
            int a = 0;
            bool flag = 0;
            for(int j=x-1;j>=0;j--){
                if(v[i][j]=='('){
                    a--;
                }else{
                    a++;
                }
                if(a<0){
                    flag =1;
                    break;
                }
            }
            if(!flag){
                r[a]++;
            }
        }
    }
    ll ans = (ll)l[0]*(ll)l[0];
    for(int i=1;i<=300000;i++){
        ans += (ll)r[i]*(ll)l[i];
    }
    cout << ans << endl;
    return 0;
}