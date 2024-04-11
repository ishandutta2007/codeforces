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
    string s,t;
    cin >> n >> s >> t;
    ll a,b,c,d;
    a=0;
    b=0;
    c=0;
    d=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            if(t[i]=='0'){
                a++;
            }else{
                b++;

            }
        }else{
            if(t[i]=='0'){
                c++;
            }else{
                d++;
            }
        }
    }
    cout << a*c+a*d+b*c << endl;
    return 0;
}