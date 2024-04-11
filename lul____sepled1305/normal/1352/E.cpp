#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int n, b,i,j;
        scanf("%d",&n);
        int val[n];
        int sum[n+1];
        bool ans[n];
        for(i=0;i<n;i++)
        {
            val[i]=0;
            sum[i]=0;
            ans[i]=false;
        }
        map<int,int> mp;
        scanf("%d",&sum[0]);
        val[0]=sum[0];
        for(i=1;i<n;i++)
        {
            scanf("%d",&b);
            sum[i] = sum[i-1]+b;
            val[i] = b;
        }
        for(i=1;i<n;i++)
        {
            int tar = val[i];
            int pointer = 0;
            while(sum[pointer]<tar)
            {
                pointer++;
            }
            if(sum[pointer]==tar && pointer!=0)
            {
                ans[i] = true;
                continue;
            }
            for(j=0;j<n-1;j++)
            {
                while(sum[pointer]-sum[j] < tar)
                {
                    pointer++;
                    if(pointer>=n)
                    {
                        pointer--;
                        break;
                    }
                }
                if(sum[pointer]-sum[j] == tar && pointer!=j+1)
                {
                    ans[i] = true;
                    break;
                }
            }
        }
        int pointer = 1;
        int tar = val[0];
        for(j=0;j<n-1;j++)
        {
            while(sum[pointer]-sum[j] < tar)
            {
                pointer++;
                if(pointer>=n)
                {
                    pointer--;
                    break;
                }
            }
            if(sum[pointer]-sum[j] == tar&& pointer!=j+1)
            {
                ans[0] = true;
                break;
            }
        }
        int counti = 0;
        for(i=0;i<n;i++){
            if(ans[i]){
                counti++;
            }
        }
        cout<<counti<<"\n";
    }
}