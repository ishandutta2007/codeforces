#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;

int n;

string a,b;

vector<int> outp={};

void push(int i)
{
    if(a[i]==b[i])return;

    outp.push_back(i);
    if(i)
    {
        outp.push_back(0);
        outp.push_back(i);
    }
}

void push_together(int i)
{
    outp.push_back(i+1);
    outp.push_back(1);
    outp.push_back(i+1);
}
void query()
{
    cin>>n>>a>>b;

    outp={};

    int i=0;

    while(i<n%3)
    {
        if(a[i]!=b[i])push(i);
        i++;
    }

    while(i<n)
    {
        if(a[i]==b[i]||a[i+1]==b[i+1]||a[i+2]==b[i+2])
        {
            push(i);
            push(i+1);
            push(i+2);
        }
        else
        {
            if(a[i]==a[i+1])
            {
                push_together(i);
                push(i+2);
            }
            else if(a[i+1]==a[i+2])
            {
                push(i);
                push_together(i+1);
            }
            else
            {
                outp.push_back(i+2);
                outp.push_back(2);
                outp.push_back(i+2);
            }
        }


        i=i+3;
    }

    assert(outp.size()<=2*n);

    printf("%i\n",outp.size());
    for(auto k:outp)printf("%i ",k+1);printf("\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;

    cin>>t;

    while(t)
    {
        query();
        t--;
    }
    return 0;
}