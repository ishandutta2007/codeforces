/*
Time will come back, turning upside down
You live in the maze of all your sadness and pain
If you want more games, look beyond the gate
I believe there is an unlimited beautiful world out there
Come what may, I'll reach there
(Although I know it is not easy)
An experiment was a failure
The artificer of the universe
(Everything is in the hand of God)
Who wrote this story? I gotta play

We share the same fate
Do you believe in this fate?
There is nobody else like you
Who takes my heart away

The place where one road forks endlessly
From the past to the future, an infinite universe
I'll wipe my tears to smile once again
I recognize your face, your voice
This story has just begun
The endless loop world to other side

Falsifying records, searching for proofs
Feeling a strange sensation underneath my skin
Far from reality, a mysterious thing
Gravity acts on everything in the cosmos
Not a dream, yet a reality
(To prepare one for one's cause)
Is all coincidence, a trick of God
I will face it with defiance
(Everything is in the black hole)
There's a reason that I never lose

We share the same fate
Do you believe in this fate?
There is nobody else like you
Who takes my heart away

The place where a lot of feelings intersect
From the past to the future, an infinite universe
I have the ability to change destiny
I recognize your face, your voice
This story has just begun
The endless loop world to other side

The place where one road forks endlessly
From the past to the future, an infinite universe
I'll wipe my tears to smile once again
I recognize your face, your voice
This story has just begun
The endless loop world to other side
*/
#include<bits/stdc++.h>
using namespace std;
long long int n,i,j,mini,sum;
long long int w[200000];
long long int wi[200000];
long long int p[200000];
vector<vector<int>> a;
int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        vector<int> start;
        start.push_back(-1);
        a.push_back(start);
    }
    for(i=1;i<n;i++)
    {
        cin>>j;
        a[j-1].push_back(i);
        p[i]=j-1;
    }
    for(i=0;i<n;i++)
    {
        cin>>w[i];
    }
    for(i=1;i<n;i++)
    {
        if(w[i]==-1)
        {
            mini=1e12;
            for(j=1;j<a[i].size();j++)
            {
                if(mini>w[a[i][j]])
                {
                    mini=w[a[i][j]];
                }
            }
            if(mini==1e12)
            {
                w[i]=w[p[i]];
            }
            else
            {
                w[i]=mini;
            }
        }
    }
    for(i=1;i<n;i++)
    {
        wi[i]=w[i]-w[p[i]];
        if(wi[i]<0)
        {
            mini=1e13;
            break;
        }
    }
    wi[0]=w[0];
    if(mini==1e13)
    {
        cout<<-1;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            sum+=wi[i];
        }
        cout<<sum;
    }
}