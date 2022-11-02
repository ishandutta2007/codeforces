/*
Is the past distancing away, and the future approaching?
The observer will eventually become aware of the contradiction.

The world created by God is perfect and absolutely balanced.
It's a confluence of small coincidences, stacked into an astronomical miracle.
The rules and regulations of the guarded Gate are no more.

Open the eyes-----
"0" is the past, "1" is the future, but "the present" is nowhere;
this is an undeniable logic.
Open the eyes-----
Among the countless parallel lines, I settle on "blasphemy" as my choice.
Doubting our very "existence", those sceneries reflected in your eyes
are coming together and settling down.

Even the basic concept of time, denoted by clocks' two hands,
is showing distortion at the observer's will.

There has to be an absolute boundary to the knowledge bestowed by God.
It's an accident caused by foolishness, an uninvited miracle.
The rules and regulations of the locked Gate are no more.

Open the eyes-----
With my hands extended toward the speed of light,
the pulse of my memory plunges into an unfathomable logic.
Open the eyes-----
The universe still holds hidden theories of chaotic disorder;
these points, called infinite continuity, borrow the power of irregularity
and "replay" again and again.

Open the eyes-----
"0" is the past, "1" is the future, but "the present" is nowhere;
this is an undeniable logic.
Open the eyes-----
Among the countless parallel lines, I settle on "blasphemy" as my choice.
Doubting our very "existence", those sceneries reflected in your eyes
are coming together and settling down.
*/
#include<bits/stdc++.h>
using namespace std;
long long n,i,l,p,k,o,j,weight;
int main()
{
    cin>>n>>k>>p>>o>>j>>l;
    weight=n;
    for(i=k;i>0;i--)
    {
        if(i==o || i==l)
        {
            weight+=i;
            if(i==o)
            {
                weight-=p;
                if(weight<0) weight=0;
            }
            else
            {
                weight-=j;
                if(weight<0) weight=0;
            }
        }
        else
        {
            weight+=i;
        }
    }
    cout<<weight;
}