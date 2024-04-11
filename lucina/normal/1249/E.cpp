#include<bits/stdc++.h>
using namespace std;
int const maxn= 3e5+10;
int n, c;
int a[maxn], b[maxn], x, y;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> c;
    for(int i = 1 ;i< n;i ++)
        cin >> a[i];
    for(int i = 1 ;i < n;i++)
        cin >> b[i];
    cout << "0 ";
    /// x minimum cost to visit floor i by stair
    /// y minimum cost to visit floor i by lift
    y = c;
    for(int i = 2 ; i <= n ; i++){
        int ny = 1e9 + 5, nx = 1e9+5;
        ny = min(ny, x + c + b[i - 1]);
        ny = min(ny, y + b[i - 1]);
        nx = min(nx, x + a[i- 1]);
        nx = min(nx, y +a[i-1]);
        cout << min(nx, ny) << " ";
        x = nx, y = ny;
    }
}