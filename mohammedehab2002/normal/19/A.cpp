#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
class team{
    public:
        string name;
        int ga;
        int gf;
        int def;
        int points;
        team()
        {
            points=ga=gf=0;
        }
};
int cfind(team arr[],string n,int size)
{
    int i;
    for (i=0;i<size;i++)
    {
        if (arr[i].name==n)
        return i;
    }
}
int main()
{
    size_t pos;
    string t1,t2,r;
    int n,i,x,s1,s2,p1,p2;
    cin >> n;
    team arr[n];
    int m=n*(n-1)/2;
    for (i=0;i<n;i++)
    cin >> arr[i].name;
    for (i=0;i<m;i++)
    {
        cin >> r;
        pos=r.find('-');
        t1=r.substr(0,pos);
        t2=r.substr(pos+1);
        scanf ("%d:%d",&s1,&s2);
        p1=cfind(arr,t1,n);
        p2=cfind(arr,t2,n);
        arr[p1].ga+=s1;
        arr[p2].ga+=s2;
        arr[p1].gf+=s2;
        arr[p2].gf+=s1;
        if (s1>s2)
        arr[p1].points+=3;
        else if (s1<s2)
        arr[p2].points+=3;
        else
        {
            arr[p1].points++;
            arr[p2].points++;
        }
    }
    for (i=0;i<n;i++)
    arr[i].def=arr[i].ga-arr[i].gf;    
    for (i=0;i<n;i++)
    {
        for (x=i+1;x<n;x++)
        {
            if (arr[x].points>arr[i].points)
            {
                swap (arr[i].points,arr[x].points);
                swap (arr[i].ga,arr[x].ga);
                swap (arr[i].gf,arr[x].gf);
                swap (arr[i].name,arr[x].name);
                swap (arr[i].def,arr[x].def);
            }
            else if (arr[x].points==arr[i].points)
            {
                if (arr[x].def>arr[i].def)
                {
                    swap (arr[i].points,arr[x].points);
                    swap (arr[i].ga,arr[x].ga);
                    swap (arr[i].gf,arr[x].gf);
                    swap (arr[i].name,arr[x].name);
                    swap (arr[i].def,arr[x].def);
                }
                else if (arr[x].def==arr[i].def)
                {
                    if (arr[x].ga>arr[i].ga)
                    {
                        swap (arr[i].points,arr[x].points);
                        swap (arr[i].ga,arr[x].ga);
                        swap (arr[i].gf,arr[x].gf);
                        swap (arr[i].name,arr[x].name);
                        swap (arr[i].def,arr[x].def);
                    }
                }
            }
        }
    }
    string ans[n/2];
    for (i=0;i<n/2;i++)
    ans[i]=arr[i].name;
    sort (ans,ans+n/2);
    for (i=0;i<n/2;i++)
    cout << ans[i] << endl;
}