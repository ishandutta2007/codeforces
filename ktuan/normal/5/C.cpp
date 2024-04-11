#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1000010;

char a[1000010];
int n;
int *v[2000010];
int sl[MAX * 2];
int s[1000010], r[1000010];
int longest = 0, cc = 1;

int main() {
    gets(a);
    n = strlen(a);
    int total = 0;
    // v[MAX].push_back(0);
    ++sl[MAX];
    s[0] = 0;
    for(int i=0;i<n;++i) {
        if(a[i] == '(') total ++;
        else total --;
        ++sl[MAX + total];
        s[i + 1] = total;
    }
    for(int i=0;i<MAX * 2;++i) if(sl[i] > 0) v[i] = new int[sl[i]];
    memset( sl, 0, sizeof(sl));
    v[MAX][sl[MAX]++] = 0;
    for(int i=0;i<n;++i) {
        v[s[i+1]+MAX][sl[s[i+1]+MAX]++] = i + 1;
    }
    r[n + 1] = n + 1;
    for(int i=n;i>=0;--i) {
        int j = i + 1;
        while(j <= n && s[j] >= s[i]) j = r[j];
        r[i] = j;
    }
    for(int i=0;i<n;++i) {
        int nh = r[i];
        int z = s[i] + MAX;
        int id = lower_bound( v[z], v[z] + sl[z], nh) - v[z];
        --id;
        if(id >= 0) {
            int j = v[z][id];
            if(j > i) {
                if(longest < j - i) {
                    longest = j - i;
                    cc = 1;
                }
                else if(longest == j - i) {
                    cc ++ ;
                }
            }
        }
    }
    cout << longest << " " << cc << endl;
    return 0;
}