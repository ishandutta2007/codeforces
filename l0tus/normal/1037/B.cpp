#include <bits/stdc++.h>
using namespace std;
vector<int> A;
int main()
{
    int n,s,x;
    cin >> n >> s;
    int pos = (n-1)/2;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        A.push_back(x);
    }
    sort(A.begin(),A.end());
    int st = lower_bound(A.begin(),A.end(),s)-A.begin();
    int en = lower_bound(A.begin(),A.end(),s)-A.begin();
    long long  ans = 0;
    if(A[pos]==s) cout << 0;
    if(A[pos]>s)
    {
        for(int i=0; i<=pos-en; i++)
            ans+= A[en+i] - s;
        cout << ans;
    }
    if(A[pos]<s)
    {
        for(int i=0; i<=st-pos-1; i++)
        {
            ans += s - A[pos+i];
        }
        cout << ans;
    }
}