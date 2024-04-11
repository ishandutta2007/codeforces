#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,a[200100],b[200100],c[200100],d[200100],e[200100],s1,s2,i,t,k,n1,n2,m1,m2;
vector < pair <int, int> > v;
pair <int, int> q;
int main() 
{
    cin>>n;
    for (i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]==1) 
        {
            s1++;
            b[s1]=i;
            d[i]=s1;
            e[i]=s2;
            continue;
        }
        s2++;
        c[s2]=i;
        d[i]=s1;
        e[i]=s2;
    }
    for (t=1; t<=n; t++)
    {
o:      
        if (t>n) break;
        n1=0;
        n2=0;
        k=0;
        while (1)
        {
            m1=b[d[k]+t];
            m2=c[e[k]+t];
            if (k==n)
            {
                if (((n1>n2) && (a[n]==1)) || ((n1<n2) && (a[n]==2)))
                {
                    q.second=t;
                    q.first=max(n1,n2);
                    v.push_back(q);
                }
            }
            if ((m1==0) && (m2==0))
            {
                t++;
                goto o;
            }
            if (m1==0)
            {
                n2++;
                k=m2;
                continue;
            }
            if (m2==0)
            {
                n1++;
                k=m1;
                continue;
            }
            k=min(m1,m2);
            if (m1<m2) n1++;
            else n2++;
        }
    }
    int n=v.size();
    sort(v.begin(), v.end());
    cout<<n<<endl;
    for (i=0; i<n; i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    return 0;
}