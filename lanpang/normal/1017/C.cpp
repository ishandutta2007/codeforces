#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int len = 0;
    for(len = 0; len * (len + 1) < n; len ++);

    int l1 = n % len;
    int l2 = n / len - l1;

    int x = n+1;
    int pos = 0;

    for(int i=0; i<l1; i++)
    {
        x -= (len+1);
        int now = x;
        for(int j=0; j<len+1; j++)
        {
            printf("%d ", now);
            now ++;
        }
    }


    for(int i=0; i<l2; i++)
    {
        x -= (len);
        int now = x;
        for(int j=0; j<len; j++)
        {
            printf("%d ", now);
            now ++;
        }
    }



    return 0;
}