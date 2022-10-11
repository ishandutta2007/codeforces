#include <iostream>
#include <string.h>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
using namespace std;
map <string,int> p;
int max_ele(set <string> f)
{
    set <string> :: iterator it=f.begin();
    int maxi=0;
    string fruit=*it;
    for (it=f.begin();it!=f.end();it++)
    {
        if (p[*it]>maxi)
        {
            maxi=p[*it];
            fruit=*it;
        }
    }
    p[fruit]=0;
    return maxi;
}
int main()
{
    int n,m,i,a,ans1=0,ans2=0;
    cin >> n >> m;
    deque <int> p1(n),p2(n);
    deque <string> d;
    set <string> f;
    string s;
    for (i=0;i<n;i++)
    cin >> p1[i];
    p2=p1;
    sort(p1.begin(),p1.end());
    sort (p2.begin(),p2.end());
    reverse(p2.begin(),p2.end());
    for (i=0;i<m;i++)
    {
        cin >> s;
        f.insert(s);
        d.push_back(s);
        p[s]=0;
    }
    for (i=0;i<m;i++)
    p[d[i]]++;
    do
    {
        a=max_ele(f);
        ans2+=a*p1.back();
        ans1+=a*p2.back();
        p1.pop_back();
        p2.pop_back();
    }while(a && p1.size());
    cout << ans1 << " " << ans2;
}