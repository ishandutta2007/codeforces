#include <iostream>

using namespace std;
typedef long long ll;

int dig[]={6,2,5,5,4,5,6,3,7,6};
ll m[]={0,2383340,5033340,7983340,10933340,13783340,16733340,19783340,22533340,25683340,28733340};

ll sum(ll a)
{
    int res=0;
    if (a==0) return 6;
    while (a)
    {
        res+=dig[a%10];
        a/=10;
    }
        return res;
}

int main()
{
    ll t,ra=0, rb=0, a, b, RES,R=0;
    cin>>a>>b;
    a--;
    ra+=m[a/100000];
    t=a-a%100000;
    for (;t<=a;t++) ra+=sum(t);

    rb+=m[b/100000];
    t=b-b%100000;
    for (;t<=b;t++) rb+=sum(t);
    if (a==-1) RES=rb;
    else RES=rb-ra;
    cout<<RES;

    //for (ll i=a+1;i<=b;i++) R+=sum(i);
    //cout<<R;
    return 0;
}