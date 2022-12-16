#include<bits/stdc++.h>
using namespace std;
const int nmax=1.5e3+42;
int seen[nmax];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
set<int> s;
bool ask(int a,int b,int c)
{
    printf("? %i %i %i\n",a,b,c);
    string s;
    cin>>s;
    return s=="Yes";
}
int main()
{
int n,k;
scanf("%i%i",&n,&k);
int h=1;
int total=1,now=1;
while(total<n)
{
    now=now*k;
    h++;
    total=total+now;
}

for(int t=1;t<=60;t++)
{
    int a=rng()%n+1;
    int b=rng()%n+1;
    s={};
    for(int j=1;j<=n;j++)
        if(ask(a,j,b))s.insert(j);
    if(s.size()==2*h-1)
    {
        for(auto now:s)
        {
            int ok=0;
            for(auto p:s)
                for(auto q:s)
                if(p<=q)
                    if(ask(p,now,q))ok++;
            if(ok==h*h)
            {
                printf("! %i\n",now);
                exit(0);
            }
        }
    }
}
return 0;
}