#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, A[200010], B[200010];
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d %d", &n, &k);
        for(i=0;i++<n;)scanf("%d", &A[i]);
        a=0, b=n-1;
        while(a<b)
        {
            int m=a+b>>1;
            for(i=0;i++<n;)B[i]=0;
            for(i=0;i++<n;)
            {
                B[max(1, A[i]-m)]++;
                B[A[i]+1]--;
            }
            for(i=0;i++<n;)B[i]+=B[i-1];
            int mx=0, ind=0;
            for(i=0;i++<n;)
            {
                if(mx<B[i])
                {
                    mx=B[i];
                    ind=i;
                }
            }
            if(2*mx-n<k)a=m+1;
            else b=m;
        }
        int m=a;
        for(i=0;i++<n;)B[i]=0;
        for(i=0;i++<n;)
        {
            B[max(1, A[i]-m)]++;
            B[A[i]+1]--;
        }
        for(i=0;i++<n;)B[i]+=B[i-1];
        int mx=0, ind=0;
        for(i=0;i++<n;)
        {
            if(mx<B[i])
            {
                mx=B[i];
                ind=i;
            }
        }
        printf("%d %d\n", ind, ind+m);
        if(k==1)
        {
            printf("1 %d\n", n);
            continue;
        }
        for(i=0;i++<n;)B[i]=((ind<=A[i])&&(A[i]<=ind+m));
        a=0;
        int prev=0;
        for(i=0;i++<n;)
        {
            a+=B[i];
            if(B[i]==0)a--;
            if(a>0)
            {
                printf("%d %d\n", prev+1, i);
                prev=i;
                k--;
                a=0;
                if(k==1)
                {
                    printf("%d %d\n", i+1, n);
                    break;
                }
            }
        }
    }
}