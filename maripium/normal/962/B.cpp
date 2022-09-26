#include<bits/stdc++.h>
using namespace std;

int n, a, b;
int ans = 0;
string s;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
    cin >> n >> a >> b >> s;
    s = '~' + s;
    for(int i = 1; i <= n; ++i)
        if(s[i] == '.') {
            if(s[i - 1] != '.' && s[i - 1] != '1' && s[i - 1] != '2'){
                if(a > b) {
                    --a; ++ans;
                    s[i] = '1';
                }
                else {
                    if(b) --b, ++ans;
                    s[i] = '2';
                }
            }
            else {
                if(s[i - 1] == '1') {
                    if(b) --b, ++ans;
                    s[i] = '2';
                }
                else {
                    if(a) --a, ++ans;
                    s[i] = '1';
                }
            }
        }
    cout << ans;
}