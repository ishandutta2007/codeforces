#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n,k,a,m,kol,q[200000],l;
    map <int,int, less <int> > i;
    map <int,int, less <int> >::iterator s,s2;
    cin>>n>>k>>a>>m;
    for (l=0;l<m;l++)
        cin>>q[l];
    //i.resize(m+2);
    i[0]=0;
    i[n+1]=(n+1)/(a+1);
    kol=i[n+1];
    l=0;
    while (kol>=k&&l<m)
    {
        i[q[l]]=-1;
        s=i.find(q[l]);
        s2=s;
        s2++;
        kol-=(*s2).second;
        (*s2).second=((*s2).first-q[l])/(a+1);
        kol+=(*s2).second;
        s2=s;
        s2--;
        i[q[l]]=(q[l]-(*s2).first)/(a+1);
        kol+=i[q[l]];
        l++;
    }
    if (l==m&&kol>=k) cout<<-1; else cout<<l;
    return 0;
}