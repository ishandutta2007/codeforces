#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef long long LL;

map<string, int> macros;

bool onlyMultiplication[200];
bool single[200];
bool bad[200];

int nMacros;

int n;

char buf[505];

char opType[255];

string getNext(int l) {
    string s = "";
    if (buf[l] == '(') {
        int z = 1;
        s += buf[l++];
        for (; z > 0; ++l) {
            s += buf[l];
            if (buf[l] == '(')
                ++z;
            else if (buf[l] == ')')
                --z;
        }
        return s;
    }
    for (; buf[l] != '*' && buf[l] != '-' && buf[l] != '+' && buf[l] != '/' && buf[l] && buf[l] != ')'; ++l)
        s += buf[l];
    return s;
}

bool badExpression(int l, int r, int cMacro = 0) {
    char pop = 'x';
    char nop = 'x';
    bool gadd = 0;
    bool nsingle = 0;
    while (l <= r) {
        if (nop == '+' || nop == '-')
            gadd = 1;
        pop = nop;
        string s = getNext(l);
        l += s.size();
        if (l <= r) {
            nop = buf[l];
        } else {
            nop = 'x';
        }
        if (s[0] == '(') {
            if (badExpression(l - s.size() + 1, l - 2))
                return 1;
        } else {
            int c = macros[s];
            if (c > 0) {
                gadd |= !onlyMultiplication[c];
                nsingle |= !single[c];
                if (bad[c])
                    return 1;
                if ((pop == '*' || nop == '*' || nop == '/' || pop == '-') && !onlyMultiplication[c])
                    return 1;
                if (pop == '/' && !single[c])
                    return 1;
            }
        }
        ++l;
    }
    if (cMacro) {
        onlyMultiplication[cMacro] = !gadd;
        single[cMacro] = bool(pop == 'x' && !nsingle);
    }
    return 0;
}

void addMacro() {
    int l = 0;
    int r = strlen(buf);
    while (buf[l] != 'n')
        ++l;
    l += 2;
    while (buf[l] == ' ')
        ++l;
    string name = "";
    while (buf[l] != ' ')
        name += buf[l++];
    int z = 0;
    for (int i = l; i < r; ++i)
        if (buf[i] != ' ')
            buf[z++] = buf[i];
    r = z;
    l = 0;
    buf[r] = 0;
    ++nMacros;
    bad[nMacros] = badExpression(l, r, nMacros);
    int cnt = 0;
    macros[name] = nMacros;
}

char final[] = "#define % ";

int main() {
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        gets(buf);
        addMacro();
    }
    for (int i = 0; i < 10; ++i)
        buf[i] = final[i];
    gets(buf + 10);
    addMacro();
    printf(bad[nMacros] ? "Suspicious\n" : "OK\n");
}