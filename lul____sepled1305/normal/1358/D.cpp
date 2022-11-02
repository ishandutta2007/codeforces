/*Our wings could soar through the sky, but we chose to exchange them for hands we could link together
But is it such a crime to still be fascinated by the sky and let our dreams combine?

Summer sees the departing of fall and remembers the look on its face
Is it full of longing, or full of love? Either way, its clear it could never be fulfilled

Todays the once-in-a-millennium day that gravity falls asleep
So lets stand where the sun cant see, and leave this planet

When he wakes up, lets go to some place we can never return again
Lets kick off the earth with a ready, go, and head to some planet other than this one

Lets go

Just a little further till were beyond destiny, just a little further till were beyond civilization
Just a little further till were beyond destiny, just a little further

We filled our sails with all of our dreams, passing through the night for the day to come
With our hopes enough to fill our tanks, we threw our arms around each others shoulders as if to say itll all work out somehow

Theres no way we arent scared, but we still wont stop
Even if we have to take some tough detours, we cant avoid it
Our love saysits voice says

It says go!*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,x,i,j,pointer1=0;
    long long maxi=0, cur = 0;
    cin>>n>>x;
    long long month[2*n+1];
    long long quick[2*n+1];
    long long quick_sum[2*n+1];
    long long pointer2 = n;
    for(i=0;i<n;i++)
    {
        cin>>month[i];
        if(i==0)
        {
            quick[i] = ((month[0]+1)*month[0])/2;
            quick_sum[i] = month[i];
        }
        else
        {
            quick[i] = quick[i-1] + ((month[i]+1)*month[i])/2;
            quick_sum[i] = month[i]+quick_sum[i-1];
        }
    }
    for(i=n;i<2*n;i++)
    {
        quick[i] = quick[i-1] + ((month[i-n]+1)*month[i-n])/2;
        quick_sum[i] = month[i-n]+quick_sum[i-1];
    }
    while(pointer2<2*n)
    {
        while(quick_sum[pointer2]-quick_sum[pointer1] >= x)
            pointer1++;
        pointer1--;
        long long pre = quick[pointer2]-quick[pointer1];
        long long over = quick_sum[pointer2]-quick_sum[pointer1] - x;
        pre-=(over*(over+1))/2;
        if(pre>maxi)
            maxi = pre;
        pointer2++;
    }
    cout<<maxi;
    return 0;
}