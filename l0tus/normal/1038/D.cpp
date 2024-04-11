#include <bits/stdc++.h>
using namespace std;

int n,arr[500010];
long long sum=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    bool isplus = false, isminus = false;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        if(arr[i]>0) isplus = true;
        if(arr[i]==0)
        {
            isplus = true;
            isminus = true;
        }
        if(arr[i]<0)
        {
            arr[i] = -arr[i];
            isminus = true;
        }
    }
    sort(arr,arr+n);
    if(n==1)
    {
        if(isminus) cout << -1*arr[0];
        else cout << arr[0];
        return 0;
    }
    for(int i=1; i<n; i++) sum += arr[i];
    if(isplus == false || isminus == false) sum -= arr[0];
    else sum += arr[0];
    cout << sum;
}