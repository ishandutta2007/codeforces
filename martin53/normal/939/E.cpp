#include<bits/stdc++.h>
using namespace std;
const int qmax=5*5e5+42;
long long pref[qmax],a[qmax];
int n;
void query()
{
double ans=a[n];
int ok=0,not_ok=n,av;
while(not_ok-ok>1)
{
av=(ok+not_ok)/2;
    if(a[n]>=pref[av+1]*(av+1)-pref[av]*(av+2))ok=av;
    else not_ok=av;
}

ok++;
ans=ans-1.0*(a[n]+pref[ok])/(ok+1);
printf("%.18f\n",ans);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();

int q,x;
cin>>q;

for(int i=1;i<=q;i++)
{
int type;
cin>>type;
if(type==2)query();
    else
    {
    cin>>x;
    n++;
    a[n]=x;
    pref[n]=pref[n-1]+a[n];
    }

}
return 0;
}