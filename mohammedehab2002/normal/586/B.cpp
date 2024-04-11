#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector <int> t;
    int n,i,ans1=0,ans2=0;
    cin >> n;
    int a1[n-1],a2[n-1],arr[n];
    for (i=0;i<n-1;i++)
    cin >> a1[i];
    for (i=0;i<n-1;i++)
    {
        cin >> a2[i];
        ans2+=a2[i];
    }
    for (i=0;i<n;i++)
    cin >> arr[i];
    t.push_back(ans2+arr[0]);
    for (i=0;i<n-1;i++)
    {
        ans1+=a1[i];
        ans2-=a2[i];
        t.push_back(ans1+ans2+arr[i+1]);
    }
    sort (t.begin(),t.end());
    cout << t[0]+t[1];
}