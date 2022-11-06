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
    vector<int> a(n);
    int d;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    d=a[1]-a[0];
    for(int i=1;i<n;++i){
        if(a[i]-a[i-1]!=d){
            cout<<a[n-1]<<endl;
            return 0;
        }
    }
    cout<<a[n-1]+d;
}