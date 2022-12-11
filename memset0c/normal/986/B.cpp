#include<bits/stdc++.h>
using namespace std;

//12132112

const int N = 1000000 + 10;

int a[N], w[N];
int n;

inline int read() {
    int f = 0, fu = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
    while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
    return f * fu;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        a[i] = read();
        w[a[i]] = i;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] != i) {
            ans++;
            int tmp = a[i];
            swap(a[i], a[w[i]]);
            w[tmp] = w[a[i]];
        }
    }
    if(n % 2 == ans % 2) printf("Petr");
    else printf("Um_nik");
    return 0;
}