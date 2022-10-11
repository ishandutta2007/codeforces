#include <bits/stdc++.h>
using namespace std;
void quickSort(int *a, int l, int r)
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
            if (i < j) swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j) quickSort(a, l, j);
    if (i < r) quickSort(a, i, r);
}
main()
{
    int n, a[1000000], start, ans;
    scanf("%d%d",&n,&start);;
    for (int i = 0; i < n; i++) {scanf("%d",&a[i]);}
    quickSort(a,0,n-1);
    ans = min(min(abs(start-a[0]),abs(start-a[n-2])) + a[n-2] - a[0],min(abs(start-a[1]),abs(start-a[n-1])) + a[n-1] - a[1]);
    cout<<((n == 1)?0:ans);
}