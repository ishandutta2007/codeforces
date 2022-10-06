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
        string a,b,c;
        cin >> a >> b >> c;
        int n = a.size();
        int m = b.size();
        int r[26]={},p[26]={},q[26]={};
        rep(i,a.size()){
            p[a[i]-'a']++;
        }
        rep(i,b.size()){
            q[b[i]-'a']++;
        }
        rep(i,c.size()){
            r[c[i]-'a']++;
        }
        int bid = 0;
        bool flag = 0;
        rep(aid,n){
            if(bid==m){
                flag = 1;
            }
            while(bid!=m){
                if(b[bid]!=a[aid]){
                    bid++;
                    if(bid==m){
                        flag = 1;
                    }
                }else{
                    bid++;
                    break;
                }
            }
        }
        if(flag){
            cout << "NO" << endl;
        }else{

            rep(i,26){
                if(p[i]+r[i]<q[i]){
                    cout << "NO" << endl;
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                cout << "Yes" << endl;
            }
        }
    }


    return 0;
}