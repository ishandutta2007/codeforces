#include <bits/stdc++.h>

using namespace std;

const int N = 15;
const string start[] = {"1990", "1991", "1992", "1993", "1994", "1995", "1996", "1997", "1998", "1989"};

int t;
char abb[N];

void increment(string &s, int pos) {
    if (s.size() <= pos) {
        s += "1";
    } else {
        for (int i = pos; i < s.size(); i++) {
            if (s[i] == '9') {
                s[i] = '0';
                if (i == s.size() - 1) {
                    s += "0";
                }
            } else {
                s[i]++;
                break;
            }
        }
    }
}

int main() {

    scanf("%d", &t);

    while (t--) {
        scanf(" IAO'%s", abb);
        string number(abb);
        string res = start[number.back() - '0'];
        reverse(number.begin(), number.end());
        reverse(res.begin(), res.end());
        for (int i = 1; i < number.size(); i++) {
            char d = number[i];
            if (res.size() <= i) {
                res += "0";
            }
            if (d == res[i]) {
                increment(res, i + 1);
            } else {
                if (res[i] > d) {
                    increment(res, i + 1);
                }
                res[i] = d;
            }
        }
        reverse(res.begin(), res.end());
        printf("%s\n", res.c_str());
    }

    return 0;
}