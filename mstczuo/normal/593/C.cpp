# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

int x[120], y[120], r[120];

char buff[120];

string solve(int a[],int n) {
    string ans;
    for(int i = 0; i < n; ++i) if(a[i]) {
        sprintf(buff, "(%d*((1-abs((t-%d)))+abs((abs((t-%d))-1))))", a[i]/2, i, i);
        if(ans.empty()) ans = string(buff);
        else ans = "(" + ans + "+" + string(buff) + ")";
    }
    if(ans=="")ans="0";
    return ans;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> r[i];
        if(x[i] & 1) x[i] ^= 1;
        if(y[i] & 1) y[i] ^= 1;
    }
    cout << solve(x, n) << endl;
    cout << solve(y, n) << endl;
    return 0;
}