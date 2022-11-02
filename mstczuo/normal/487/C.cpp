# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

bool check(int n) {
    if(n % 2 == 0) return false;
    for(int i = 3; i*i <= n; i+=2) 
        if(n % i == 0) return false;
    return true;
}

int power(int a,int b,int p) {
    int t = 1;
    while(b > 0) {
        if(b & 1) t = 1ll*t*a%p;
        a = 1ll*a*a%p;
        b = b >> 1;
    }
    return t;
}

const int MAXN = 100010;
int divs[MAXN];
int primitive_root(const int p) {
    int cnt = 0, m = p-1;
    for(int i = 2; i*i <= m; i++) if(m%i==0) {
        divs[cnt++] = i;
        if(i*i < m) divs[cnt++] = m/i;
    }
    int r = 2, j = 0;
    while(true) {
        for(j=0; j<cnt; ++j)
            if(power(r, divs[j], p) == 1) break;
        if(j >= cnt) return r; r++;
    }
    return -1;
}


int main() {
    int n;
    cin >> n;
    if(n == 1) puts("YES\n1"); 
    else if(n == 2) puts("YES\n1\n2"); 
    else if(n == 3) puts("YES\n1\n2\n3"); 
    else if(n == 4) puts("YES\n1\n3\n2\n4");
    else {
        if(!check(n)) {
            puts("NO");
        } else {
            puts("YES");
            int s = primitive_root(n);
            cout << 1 << endl;
            cout << s << endl;
            int t = n - 3;
            for(int i = 3; i < n-1; i += 2) {
                if(t--)cout << power(s,n-i,n) << endl;
                if(t--)cout << power(s,i,n) << endl;
            }
            cout << n << endl;
        }
    }
}