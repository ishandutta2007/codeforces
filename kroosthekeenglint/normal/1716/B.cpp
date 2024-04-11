#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[100005];
void print_a(int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("%d ",a[i]+1);
    }
    printf("\n");
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    int zu;
    for (zu=0;zu<t;zu++)
    {
        int n;
        scanf("%d",&n);
        int i;
        for (i=0;i<n;i++)
        {
            a[i] = i;
        }
        printf("%d\n",n);
        print_a(n);
        swap(a[0],a[n-1]);
        print_a(n);
        for (i=0;i<n-2;i++)
        {
            swap(a[i],a[i+1]);
            print_a(n);
        }
    } 
    return 0;
}