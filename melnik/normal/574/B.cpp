#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,a,b,kol=2e9,l,k,x,y,z[4001];
    vector <int> i[4001];
    cin>>n>>m;
    for (l=0;l<=n;l++) z[l]=0;
    for (;m>0;m--)
    {
        cin>>a>>b;
        z[a]++;
        z[b]++;
        i[a].push_back(b);
        i[b].push_back(a);
    }
    for (m=1;m<=n;m++)
        sort(i[m].begin(),i[m].end());
    for (m=1;m<=n;m++){
        k=i[m].size();
        for (l=0;l<k;l++)
        {
            x=0;
            y=0;
            while (x<i[m].size()&&y<i[i[m][l]].size())
            {
                if (i[m][x]<i[i[m][l]][y]) {x++; continue;}
                if (i[m][x]>i[i[m][l]][y]) {y++; continue;}
                if (i[m][x]==i[i[m][l]][y]) {kol=min(kol,z[m]+z[i[m][l]]+z[i[m][x]]-6);x++;}
            }
        }
    }
    if (kol==2e9) cout<<-1; else cout<<kol;
    return 0;
}