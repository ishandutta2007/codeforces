#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int n;
long long ans;
map<long long, int> events;

int main(){
    //freopen("b.in", "r", stdin);
    scanf("%d", &n);
    events.clear();
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        ++events[x]; ans += x;
    }
    for (int i = 1; i < n; i++) 
    {
        map<long long, int>::iterator itr = events.end();
        --itr;
        long long value = itr->first;
        if (!(--(itr->second))) events.erase(itr);itr = events.end();
        --itr;
        value += itr->first;
        if (!(--(itr->second))) events.erase(itr);
        ans += value;
        ++events[value];
    }
    cout << ans << endl;
}