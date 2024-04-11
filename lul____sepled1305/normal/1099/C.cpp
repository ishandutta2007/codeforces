/*
Saying "ignorance is bliss" even about tomorrow's weather, you forego your umbrella
If it turns out to be a rain of tears, then it's been overwritten by an overly gentle lie

The pieces of the sky trapped in the box
will not fit into the puzzle of the future
An uncountable number of deductions spit out noise,
a logic that deceives even the gods,
towards that place of promise

Even though we still don't understand the universe, we open the gate of zero
Everything is becoming grains and will regenerate back
If so, then I'll show you that I'll even hold together your visibly unstable conciousness
At that time, that place, your "time" begins one more time

Precious memories are denied by another theoretical formula
Even the event horizon, and its very creation, was overwritten

The pieces of love trapped in the box
Are close, and yet too distant on the far side of the dimension
The process of alteration, very innocently,
is a fiction that deceives even the gods,
proceeding towards that place of promise

Soon, the bells of the clock will be ringing, and we will open the gate of zero
We will be continuously enveloped in a bright light
With miracles overwritten as fates, laughing voices will overflow
At that time, that place, your "time" begins one more time

Even though we still don't understand the universe, we open the gate of zero
Everything is becoming grains and will regenerate back
If so, then I'll show you that I'll even hold together your visibly unstable conciousness
At that time, that place, your "time" begins one more time
*/
#include<bits/stdc++.h>
using namespace std;
int n,k,l,p,i,st;
char c[500];
int main()
{
    scanf("%s",&c);
    cin>>k;
    while(c[i]!='\0')
    {
        if(c[i]=='?')
        {
            l++;
        }
        if(c[i]=='*')
        {
            p++;
        }
        i++;
    }
    if(k<i-2*l-2*p)
    {
        cout<<"Impossible";
    }
    else if (p==0 && k>i-l)
    {
        cout<<"Impossible";
    }
    else
    {
        st=k-i+l+p;
        if(st<0)
        {
            i=0;
            while(c[i]!='\0')
            {
                if(c[i+1]=='?' || c[i+1]=='*')
                {
                    if(st<=-1)
                    {
                        i+=2;
                        st++;
                    }
                    else if(st==0)
                    {
                        cout<<c[i];
                        i+=2;
                    }
                }
                else
                {
                    cout<<c[i];
                    i++;
                }
            }
        }
        else if(st==0)
        {
            i=0;
            while(c[i]!='\0')
            {
                if(c[i]!='*' && c[i]!='?')
                {
                    cout<<c[i];
                }
                i++;
            }
        }
        else
        {
            i=0;
            while(c[i]!='\0')
            {
                if(c[i+1]=='*')
                {
                    //cout<<"..............................";
                    if(st>0)
                    {
                        st--;
                        cout<<c[i];
                    }
                    else
                    {
                        cout<<c[i];
                        i++;
                    }
                }
                else if(c[i]!='?' && c[i]!='*')
                {
                    cout<<c[i];
                    i++;
                }
                else
                {
                    i++;
                }
            }
        }
    }
    return 0;
}