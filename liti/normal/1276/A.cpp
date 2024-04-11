//be naame khodaa
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <numeric>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int N = -1;

int main() {
    int t;
    cin >> t; 

    for(int i = 0; i < t; i++) { 
        string s; 
        cin >> s; 
        vector<int> ans; 

        for(int i = 2; i < sz(s); i++) { 
            string sub = s.substr(i-2, 3);
            if( sub == "one" || sub == "two" ) {
                if( sub == "two" && i + 2 < sz(s) && s[i+1]=='n' && s[i+2]=='e') 
                    ans.pb(i+1); 
                else
                    ans.pb(i);
                i += 2; 
            }
        }

        cout << sz(ans) << '\n'; 
        for(auto x : ans)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}