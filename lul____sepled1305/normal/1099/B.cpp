/*
Even the number of the billions of the heartbeats,
to you, is a trifle no more than a blink of the eye.
Although I'm trapped in the past and lamenting at the future,
I must not allow even a dust-sized miscalculation.

We have been given the theory of the right to brag vainly about
both our "infinitely" expanding dream and our sketched future.
The two hands of the clock point out the "finite" factor.
I head towards a cruel contract and choice, hacking to the gate--

That's why, at this very moment, in the interval of a second,
I wish to cross the world lines and protect your smile.
Then, once again into a time loop devoid of misery,
I will be swallowed as a lonely observer.

Even life's viewpoints and meaningless proofs,
to you, are so laughable that you can't even use them to relieve your boredom.
The foolish people of that race, acting as if they were the rulers of all,
have presented childish theorems that reek of their conceitedness.

We have been shown the freedom to imagine things
such as "infinite" love and what's beyond the sky.
The "finite" is what's mercilessly allowing time to flow on,
as I head towards my choice to deny even tomorrow, hacking to the gate--

I must not pretend that I've never made any promise
with my friends back in those brilliant days.
Therefore, I am a lonely observer with no more doubt
in my remaining tricks that I will use to deceive time.

That's why, at this very moment, in the interval of a second,
I wish to cross the world lines and protect your smile.
Then, once again into a time loop devoid of misery,
I will be swallowed as a lonely observer.
*/
#include<bits/stdc++.h>
using namespace std;
int n,j,l=1,p=1,i,area=1;
int main(){
    cin>>n;
    while(area<n)
    {
        if(l<p)
        {
            l++;
        }
        else
        {
            p++;
        }
        area=l*p;
    }
    cout<<l+p;
}