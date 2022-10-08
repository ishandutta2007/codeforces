#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

char s[100010];
char a[111], b[111];
int na, nb, ns;

bool test(char *s, char *a, int n) {
    for(int i=0;i<n;++i) if(a[i] != s[i]) return false;
    return true;
}

bool check(char *s, char *a, char *b) {
    for(int i=0;i + na<=ns;++i) if(test( s + i, a, na)) {
        for(int j=i+na;j+nb<=ns;++j) if(test( s + j, b, nb)) {
            return true;
        }
        break;
    }
    return false;
}

int main() {
    gets(s); gets(a); gets(b);
    ns = strlen(s);
    na = strlen(a);
    nb = strlen(b);
    bool b1 = check( s, a, b);
    reverse( s, s + ns);
    bool b2 = check( s, a, b);
    if(b1 && b2) cout << "both";
    else if(b1) cout << "forward";
    else if(b2) cout << "backward";
    else cout << "fantasy";
    return 0;
}