#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
using namespace std;

typedef long long ll;
#define F first
#define S second
#define pb push_back

int main() {
    ios_base::sync_with_stdio(0);
    string a, s;
    cin >> a >> s;
    int cnt[10];
    for(int i = 0; i < 10; ++i)
            cnt[i] = 0;
    for(int i = 0; i < s.length(); ++i)
            cnt[s[i] - '0']++;
    for(int i = 0; i < a.length(); ++i) {
            int cur = a[i] - '0';
            int top = 9;
            while(cnt[top] == 0 && top > cur)
                           --top;
            if(top > cur)
                   --cnt[top];
            cout << char(top + '0');
    }
    cin >> s;
    return 0;
}