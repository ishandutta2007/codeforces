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

template<typename T>
vector<T> divisor(T n)
{
    vector<T> res;
    for(T i=1;(long long)i*i<=n;i++){
        if(n%i==0){
            if(n!=i){
                res.push_back(i);
            }
            if(i != n/i&&n/i!=n){
                res.push_back(n/i);
            }
        }
    }
    sort(res.rbegin(),res.rend());
    return res;
}


int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> v = divisor(n);
    vector<int> a(n+1);
    a[n] = 1;
    for(int x:v){
        a[x] = n/x;
        for(int i=2*x;i<=n;i+=x){
            a[x] -= a[i];
        }
    }
    int res = 0;
    for(int x:v){
        bool flag = 1;
        for(int i=0;i<x;i++){
            int id = i;
            int c = 0;
            while(1){
                if(s[id]=='1')c++;
                id += x;
                id %= n;
                if(id==i)break;
            }
            if(c%2==1)flag = 0;
        }
        if(flag){
            res += a[x];
        }
    }
    bool flag = 1;
    for(int i=0;i<n;i++){
        if(s[i]!='0'){
            flag = 0;
        }
    }
    if(flag)res++;
    cout << res << endl;
    return 0;
}