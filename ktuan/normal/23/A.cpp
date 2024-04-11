#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

string s;

int main() {
    cin >> s;
    int max = 0;
    int n = s.length();
    Rep(i,n)Rep(j,i) {
        string  s2 = s.substr(j,i-j);
        int id = s.find(s2);
        if(id != string::npos) {
            int id2 = s.substr(id+1).find(s2);
            if(id2 != string::npos) {
                if(max < i-j) max = i-j;
            }   
        }
    }
    cout << max << endl;
    return 0;   
}