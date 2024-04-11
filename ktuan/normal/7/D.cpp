#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 5000050;

char a[MAX];
char b[MAX];
int next[MAX];
int deg[MAX];
int n;
bool palin[MAX];

int main() {
    gets(a);
    n = strlen(a);
    memmove( b, a, sizeof(a));
    reverse( a, a + n);
    next[0] = -1;
    for(int i=1;i<n;++i) {
        int j = next[i-1];
        while(b[j+1] != b[i]) {
            if(j >= 0) j = next[j];
            else break;
        }
        if(b[j+1] == b[i]) next[i] = j + 1;
        else next[i] = -1;
    }
    int t = -1;
    for(int i=0;i<n;++i) {
        while(b[t+1] != a[i]) {
            if(t >= 0) t = next[t];
            else break;
        }
        if(b[t+1] == a[i]) ++t;
        else t = -1;
    }
    while(t >= 0) {
        palin[t] = true;
        t = next[t];
    }
    // for(int i=0;i<n;++i) if(palin[i]) cout << i << " " ;
    // cout << endl;
    long long z = 0;
    for(int i=0;i<n;++i) 
        if(palin[i]) {
            deg[i] = 1;
            if(i > 0)
                deg[i] = max( deg[i], deg[(i-1)/2] + 1);
            z += deg[i];
        }
    cout << z << endl;
    return 0;
}