#include <bits/stdc++.h>
using namespace std;

stack<string> st;
string str;

int main() {
    long long cnt = 0, tot = 0;
    long long n, p;
    scanf("%lld%lld", &n, &p);
    p >>= 1;
    for (int i = 1; i <= n; i++) cin >> str, st.push(str);
    while (!st.empty()) {
        cnt <<= 1;
        if (st.top() == "halfplus") cnt++;
        st.pop();
        tot += cnt;
    }
    printf("%lld\n", tot * p);
    return 0;
}
/////////////////////////////////////