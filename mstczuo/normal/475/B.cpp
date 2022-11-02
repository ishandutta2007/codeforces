# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    --n; --m;
    char s[30], t[30];
    cin >> s >> t;
    bool flag = true;
    if(s[0] == '>' && t[0] == 'v') flag = false;
    if(s[0] == '<' && t[m] == 'v') flag = false;
    if(s[n] == '>' && t[0] == '^') flag = false;
    if(s[n] == '<' && t[m] == '^') flag = false;
    if(flag)puts("YES");else puts("NO");
}