#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int a[101] , sum;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i] , sum += a[i];
    if(sum == 0)
    {
        int k = n - 1;
        while(sum == 0)
        {
            if(k < 0)
            {
                cout << "NO";
                return 0;
            }
            sum -= a[k];
            k--;
        }
        cout << "YES\n2\n" << 1 << " " << k + 1 << "\n" << k + 2 << " " << n;
        return 0;
    }
    cout << "YES\n1\n1 " << n << endl;
}