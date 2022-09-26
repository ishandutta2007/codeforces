#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;

int a[N];
string s;
int l[N], r[N];

void print(int a){
    if(a < 0)
        cout<<-a<<" L\n";
    else
        cout<<a<<" R\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    for(int i = 0; i < n; ++i){
        cin>>a[i];
    }
    sort(a, a + n);
    cin>>s;

    for(int i = 1; i < n; ++i){
        l[i] = l[i - 1];
        r[i] = r[i - 1];
        if(s[i] == s[i - 1]) --l[i];
        else ++r[i];
    }
    int d = n - 1 - r[n - 1];
    for(int i = 0; i < n; ++i){
        l[i] += d;
        r[i] += d;
    }

    if(s[n - 1] == 'L'){
        for(int i = n - 1; i >= 0; i -= 2)
            a[i] = -a[i];
    } else {
        for(int i = n - 2; i >= 0; i -= 2)
            a[i] = -a[i];
    }
    print(a[l[0]]);
    for(int i = 1; i < n; ++i){
        if(r[i] != r[i - 1])
            print(a[r[i]]);
        else
            print(a[l[i]]);
    }
}