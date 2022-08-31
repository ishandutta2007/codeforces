#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
int a[1000000];
int b[1000000];
int c[1000][1000];
vector<int> v;
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    sort(a, a+m);
    if(a[0] == 1 || a[m-1] == n){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i+2<m; i++){
        if(a[i]+1 == a[i+1] && a[i+1] +1==a[i+2]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}