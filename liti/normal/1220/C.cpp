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
    string s;
    cin >> s; 

    int n = s.size();

    char mn = char('z' + 1);

    for(int i = 0; i < n; i++) 
        if( s[i] <= mn ) { 
            mn = s[i];
            cout << "Mike\n";
        } else
            cout << "Ann\n";
    return 0;
}