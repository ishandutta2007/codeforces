/*
Spending time with you, who's always so displeased,
I've come to understand one thing, You're only pretending to be that way,
while in a frantic struggle. I never want you to change; like a block of ice,
Never melt Surely, at the end of this path, a beautiful glacier awaits, such a heart,
if you look closely, is surely within everyone. You have one as well.

I've been putting off all the things I should do, And only ever doing what I want,
I'm preparing for battles. We're at a standstill, trying to protect something,
and there are innumerable enemies; They're waiting for me ... they're waiting for you as well.

If you do, I'll immediately be able to find the way, But you can't decipher it yourself.

We'll always be together, just like lovers, Even if the summer rays grow too hot,
we'll never let go. Grand scenery awaits us, I'll listen to all your pent-up feelings, I have them as well.

*/
#include<bits/stdc++.h>
using namespace std;
long long int i,j,k,n,m,b,c,d;
long long a[300010];
int main()
{
    cin>>a[0]>>a[1]>>a[2]>>d;
    sort(a,a+3);
    if(d>a[1]-a[0])
    {
        i+=d+a[0]-a[1];
    }
    if(d>a[2]-a[1])
    {
        i+=d+a[1]-a[2];
    }
    cout<<i;
    return 0;
}