#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e2 + 20;
pair<int , int> a[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].first , a[i].second = i;
    sort(a , a + n);
    for(int i = 0; i < n / 2; i++)
    {
        cout << a[i].second + 1 << " " << a[n - i - 1].second + 1 << endl;
    }
}