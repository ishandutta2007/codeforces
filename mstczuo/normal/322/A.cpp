# include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    cout << n+m-1 << endl;
    cout << 1 << ' ' << 1 << endl;
    for(int i=2; i<=n; i++)
        cout << i << ' ' << 1 << endl;
    for(int i=2; i<=m; i++)
        cout << 1 << ' ' << i << endl;
    return 0;
}