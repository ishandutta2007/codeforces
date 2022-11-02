# include <iostream>
# include <cstdio>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if (m>=n*(n-1)/2)
    {
        printf("no solution\n");
        return 0;
    }
    for(int i=1; i<=n; i++)
        cout << 0 << ' ' << i << endl;
    return 0;
}