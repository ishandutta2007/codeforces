#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cons(int arr[],int size)
{
    int i,ans=0,maxi=0;
    for (i=0;i<size;i++)
    {
        if (arr[i])
        ans++;
        else
        {
            if (ans>maxi)
            maxi=ans;
            ans=0;
        }
    }
    if (ans>maxi)
    maxi=ans;
    return maxi;
}
int main()
{
    int n,m,q,i,x,a,b;
    cin >> n >> m >> q;
    int arr[n][m];
    vector <int> cnt(n);
    for (i=0;i<n;i++)
    {
        for (x=0;x<m;x++)
        cin >> arr[i][x];
        cnt[i]=cons(arr[i],m);
    }
    for (i=0;i<q;i++)
    {
        cin >> a >> b;
        a--;
        b--;
        arr[a][b]=1-arr[a][b];
        cnt[a]=cons(arr[a],m);
        cout << *max_element(cnt.begin(),cnt.end()) << endl;
    }
}