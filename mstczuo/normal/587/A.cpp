# include <iostream>
# include <cstdio>
# include <cstring>
# include <set>

using namespace std;

multiset<int> num;

int main() {
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        num.insert(x);
    }
    int ans = 0;
    while(num.size()) {
        int x = *num.begin();
        num.erase(num.begin());
        if(!num.empty() && *num.begin() == x) {
            num.erase(num.begin());
            num.insert(x + 1);
        } else {
            ans += 1;
        }
    }
    cout << ans << endl;
}