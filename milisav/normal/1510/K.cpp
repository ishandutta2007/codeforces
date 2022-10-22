#include <bits/stdc++.h>
using namespace std;
int n,p[2007],og[2007];
bool ok()
{
    for(int i=1;i<=2*n;i++) if(p[i]!=i) return false;
    return true;
}
void load() {for(int i=1;i<=2*n;i++) p[i]=og[i];}
void applyA() {for(int i=1;i<=2*n;i+=2) swap(p[i],p[i+1]);}
void applyB() {for(int i=1;i<=n;i++) swap(p[i],p[i+n]);}
int main()
{
    cin>>n;
    int sol = 50*n;
    for(int i=1;i<=2*n;i++) cin>>og[i];
    load();
    if(ok()) sol=0;
    for(int i=1;i<=3*n;i++)
    {
        if(i&1) applyA();
        else applyB();
        if(ok()) sol=min(sol,i);
    }
    load();
    for(int i=1;i<=3*n;i++)
    {
        if(i&1) applyB();
        else applyA();
        if(ok()) sol=min(sol,i);
    }
    if(sol==50*n) sol=-1;
    cout<<sol;
}