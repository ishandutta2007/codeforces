#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        
        string s;
        cin >> s;
        int m = s.size();
        int sm = 0;
        int c = 0;
        int k = 0;
        rep(j,m){
            if(s[j]=='0'){
                c++;
                k++;
            }else if((s[j]-'0')%2==0){
                k++;
            }
            sm += s[j]-'0';
        }
        if(sm%3==0&&c>=1&&k>=2){
            cout << "red\n";
        }else{
            cout << "cyan\n";
        }
    }
    return 0;
}