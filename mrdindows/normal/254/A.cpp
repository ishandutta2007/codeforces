#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int t[5001];
int main()
{    
freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d",&n);
    vector <pair<int,int> > a(2*n);
    for(int i = 0;i<2*n;i++)
    {
            scanf("%d",&(a[i].first));
            t[a[i].first]++;
            a[i].second = i + 1;
    }
    sort(a.begin(),a.end());  
    for ( int i = 0;i<2*n;i++)
    {
        int j = i;
        int c = 0;
        while (j < 2*n && a[j].first == a[i].first)
              j++;
        if ( (j - i) % 2 != 0)
        {
             cout << -1;
             return 0;
        }
        i = j - 1;
    }
    for(int i = 0;i<2 * n;i+=2)
    printf("%d %d\n",a[i].second,a[i+1].second );
         
    
return 0;

}