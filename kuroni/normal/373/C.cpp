#include <bits/stdc++.h>
using namespace std;
void QuickSort(int *a, int l, int r)
{
    srand(time(NULL));
    int key = a[l + rand() % (r-l+1)];
    int i = l, j = r;

    while(i <= j)
    {
        while(a[i] < key) i++;
        while(a[j] > key) j--;
        if(i <= j)
        {
            if (i < j) swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if (l < j) QuickSort(a, l, j);
    if (i < r) QuickSort(a, i, r);
}
main()
{
    ios_base::sync_with_stdio(0);
    int n, A[500000],i,j,ans=0;
    for (cin>>n,i=0;i<n;i++) cin>>A[i];
    QuickSort(A,0,n-1);
    j=n-1;
    i=n-1;
    while (j>=0)
    {
        if (A[j] <= A[i]/2) {ans++;i--;}
        j--;
        if (ans==n/2) break;
    }
    cout<<n-ans;
}