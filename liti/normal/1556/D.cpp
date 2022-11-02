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
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int N = 10000 + 100;

int ansa[N], anso[N]; 

int a[N]; 
short b[N][32];

void ask(int i, int j, int x) { 
    cout << "or " << i+1 << " " <<  j+1 << endl;
    fflush(stdout);
    cin >> anso[x];
    cout << "and " << i+1 << " " <<  j+1 << endl;
    fflush(stdout);
    cin >> ansa[x];
}

void set(int i, int j, int x, bool rev=false) { 
    for(int bit = 0; bit < 31; bit++) 
        if(b[i][bit] != -1) { 
            if(b[i][bit] == 0) 
                b[j][bit] = (anso[x]>>bit) & 1;
            else
                b[j][bit] = (ansa[x]>>bit) & 1;
        } else if(b[j][bit] == -1) {
            int ores = (anso[x]>>bit) & 1;
            int ares = (ansa[x]>>bit) & 1;
            if(ares == 1) 
                b[j][bit] = b[i][bit] = 1;
            if(ores == 0)
                b[j][bit] = b[i][bit] = 0;
        }
    if(!rev)
        set(j, i, x, true);
}

int main() {
    memset(b, -1, sizeof b);
    int n, k;
    cin >> n >> k;

    for(int i = 0; i+1 < n; i++) {
        ask(i, i + 1, i+1);
        set(i, i + 1, i+1);
    }

    ask(0, 2, 0); 
    set(0, 2, 0); 

    for(int i = 0; i+1 < n; i++) 
        set(i, i + 1, i+1);

    for(int i = 0; i < n; i++) 
        for(int bit = 0; bit < 31; bit++)
            if(b[i][bit] == 1)
                a[i] |= (1<<bit);
    sort(a, a + n);
    cout << "finish " << a[k-1] << endl;
    fflush(stdout);
    return 0;
}