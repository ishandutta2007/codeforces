#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n,i;
    cin>>n;
    int half = (n+1)/2;
    int arr[half];
    for(i=0;i<half;i++)
        cin>>arr[i];
    int fin;
    cin>>fin;
    long long cur = 0LL;
    cur+=1LL*fin*(n/2);
    if(fin>0)
    {
        for(i=0;i<half;i++)
            cur+=arr[i];
        if(cur>0)
            cout<<n;
        else
            cout<<"-1";
    }
    else
    {
        int ans = n;
        for(i=0;i<half;i++)
            cur+=arr[i];
        bool pass = false;
        int pointer = n-1;
        while(ans>n/2)
        {
            if(cur<=0 && pointer<n)
            {
                pointer--;
                ans--;
                cur-=fin;
                continue;
            }
            if(pointer<n)
            {
                pointer++;
                cur+=fin;
                cur-=arr[pointer-ans];
                continue;
            }
            if(pointer==n)
            {
                pass = true;
                break;
            }
        }
        if(pass)
            cout<<ans;
        else
            cout<<-1;
    }
    return 0;
}