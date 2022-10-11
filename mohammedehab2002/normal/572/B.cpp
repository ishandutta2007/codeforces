#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    int n,s,i,x,p,q,arr[100005],arr2[100005],c=0,c2=0;
    cin >> n >> s;
    char d;
    memset(arr,0,sizeof(arr));
    memset(arr2,0,sizeof(arr2));
    for (i=0;i<n;i++)
    {
        cin >> d >> p >> q;
        if (d=='B')
        arr[p]+=q;
        else
        {
            arr2[p]+=q;
            if (arr2[p]==q)
            c2++;
        }
    }
    int size=min(s,c2);
    pair <int,int> arr3[size];
    for (i=0;i<100005 && c<size;i++)
    {
        if (arr2[i])
        {
            arr3[c]=make_pair(i,arr2[i]);
            c++;
        }
    }
    reverse(arr3,arr3+size);
    for (i=0;i<size;i++)
    cout << "S " << arr3[i].first << " " << arr3[i].second << endl;
    for (i=100004,c=0;i>=0&& c<s;i--)
    {
        if (arr[i])
        {
            cout << "B " << i << " " << arr[i] << endl;
            c++;
        }
    }
}