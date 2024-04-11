#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

string s[1010];
int n, maxlen;

int main() {
    while(getline(cin, s[n])) ++n;
    maxlen = 0;
    for(int i=0;i<n;++i) maxlen = max( maxlen, (int)s[i].length());
    string pre(maxlen + 2, '*');
    printf("%s\n", pre.c_str());
    bool isleft = true;
    for(int i=0;i<n;++i) {
        printf("*");
        int len = s[i].length();
        int z = (maxlen - len) / 2;
        if((maxlen - len) % 2 == 0) {
            for(int t=0;t<z;++t) printf(" ");
            printf("%s", s[i].c_str());
            for(int t=0;t<z;++t) printf(" ");
        }
        else {
            if(isleft) {
                for(int t=0;t<z;++t) printf(" ");
                printf("%s", s[i].c_str());
                for(int t=0;t<=z;++t) printf(" ");
            }
            else {
                for(int t=0;t<=z;++t) printf(" ");
                printf("%s", s[i].c_str());
                for(int t=0;t<z;++t) printf(" ");
            }
            isleft = !isleft;
        }
        printf("*\n");
    }
    printf("%s\n", pre.c_str());
    return 0;
}