#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,k;

long long ask(int pos)
{
    cout<<"? "<<pos<<endl;
    cout.flush();

    long long ret;
    cin>>ret;

    return ret;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    cin>>n>>k;

    int pos;

    while(1)
    {
        pos=rng()%n+1;

        if(ask(pos)<k)break;
    }

    while(1)
    {
        pos++;

        if(pos>n)pos=pos-n;

        if(ask(pos)==k)
        {
            cout<<"! "<<pos<<endl;
            exit(0);
        }
    }


    return 0;
}