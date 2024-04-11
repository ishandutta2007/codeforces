#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    vector <int> v;
    int a,i,arr[1000005],b[1000005],e[1000005],maxi=0,n,n1=0,n2=1000000;
    memset (b,-1,sizeof(b));
    memset (arr,0,sizeof(arr));
    memset (e,-1,sizeof(e));
    cin >> n;
    for (i=0;i<n;i++)
    {
        cin >> a;
        if (b[a]==-1)
        b[a]=i;
        e[a]=i;
        arr[a]++;
    }
    for (i=0;i<1000005;i++)
    {
        if (arr[i]>maxi)
        maxi=arr[i];
    }
    for (i=0;i<1000005;i++)
    {
        if (arr[i]==maxi)
        v.push_back(i);
    }
    for (i=0;i<v.size();i++)
    {
        if (e[v[i]]-b[v[i]]<n2-n1)
        {
            n1=b[v[i]];
            n2=e[v[i]];
        }
    }
    cout << n1+1 << " " << n2+1 << endl;
}