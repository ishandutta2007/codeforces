#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 500 * 1000 + 10;
string s;
long long maxTime;
int last, n;

void init() {
    last = 0;
    for (int i = 0; i < n; ++i)
        if (s[i] == 'H')
            last = max(last, i);
}

bool check(long long candies) {
    vector<int> need;
    long long curTime = 0;
    
    for (int i = 0; i < n; ++i) {
        if (!need.size() && i > last)
            break;
        ++curTime;
        if (s[i] == 'S') {
            ++candies;
            if (need.size() && candies >= need.size()) {
                candies -= (int)need.size();
                if (need.back() != last)
                    curTime += 2 * (i - need[0]);
                else
                    curTime += (i - need[0]);
                need.clear();
            }
        }
        if (s[i] == 'H') {
            if (candies > 0)
                --candies;
            else
                need.push_back(i);
        }
    }
    curTime = min(curTime, 2ll * n - 1);
    return (need.size() == 0 && curTime <= maxTime);
}
            
            

int main() {
    ios_base::sync_with_stdio(0);
    
    cin >> n >> maxTime;
    cin >> s;
    
    init();
    long long left = 0, right = n + 1;
    while (left < right) {
        long long mid = (left + right) / 2;
        if (check(mid))
            right = mid;
        else
            left = mid + 1;
    }
    
    if (check(left))
        cout << left;
    else
        cout << -1;
   
    return 0;
}