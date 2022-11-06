#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second

const int N = 1e5 + 10;

int main() {
//    ifstream cin( "input.txt" );
    int n;
    cin >> n;
    vector <int> a(7);
    int res=0;
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for(int j=0;j<7;++j){
            a[j]+=s[j]-'0';
            res=max(res,a[j]);
        }
    }
    cout<<res<<endl;
}