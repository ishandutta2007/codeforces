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
    int n;
    cin >> n;
    if(n==1){
        cout << "? 1 " << n << endl;
        string s;
        cin >> s;
        cout << "! " << s << endl;
        return 0;    
    }
    cout << "? 1 " << n << endl;
    vector<vector<int> > a(n+1,vector<int>(26));
    for(int i=0;i<n*(n+1)/2;i++){
        string str;
        cin >> str;
        int k = str.size();
        rep(j,k){
            a[k][str[j]-'a']++;
        }
    }
    // rep(i,n+1){
    //     rep(j,26)cerr << a[i][j] << " ";
    //     cerr << endl;
    // }
    cout << "? 1 " << n-1 << endl;
    vector<vector<int> > b(n+1,vector<int>(26));
    for(int i=0;i< n*(n-1)/2;i++){
        string str;
        cin >> str;
        int k = str.size();
        rep(j,k){
            b[k][str[j]-'a']++;
        }
    }
    // rep(i,n+1){
    //     rep(j,26)cerr << b[i][j] << " ";
    //     cerr << endl;
    // }
    
    vector<char> res(n);
    
    for(int i=1;i<=n/2;i++){
        vector<int> d(26);
        for(int j=0;j<26;j++){
            d[j] = a[i][j]-b[i][j];
        }
        for(int j=n-1;j>n-i;j--){
            d[res[j]-'a']--;
        }
        // rep(j,26)cerr << d[j] << " ";
        // cerr << endl;
        
    
        for(int j=0;j<26;j++){
            if(d[j]!=0){
                res[n-i] = 'a'+j;
                break;
            }
        }
    }
    if(n%2==1){
        int k = n/2+1;
        vector<int> d(26);
        for(int j=0;j<26;j++){
            d[j] = a[k][j]-a[k-1][j];
        }
        for(int j=0;j<26;j++){
            if(d[j]!=0){
                res[k-1] = 'a'+j;
                break;
            }
        }
    }
    for(int i=n/2;i>=1;i--){
        vector<int> d(26);
        for(int j=0;j<26;j++){
            d[j] = a[i][j]-a[i-1][j];
        }
        for(int j=n/2-1;j>i-1;j--){
            d[res[j]-'a']--;
        }
        int k = n%2;
        for(int j=n/2;j < k+1+n/2+(n/2-i);j++){
            d[res[j]-'a']--;    
        }
        // rep(j,26)cerr << d[j] << " ";
        // cerr << endl;
        for(int j=0;j<26;j++){
            if(d[j]!=0){
                res[i-1] = 'a'+j;
                break;
            }
        }
    }
    cout << "! ";
    rep(i,n){
        cout << res[i];
    }
    cout << endl;
    return 0;
}