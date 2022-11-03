#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e2+20;
int a[maxn];
/*ll sum;
ll sum1;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>-1;i--)
    {
        sum1+=a[i];
        sum-=a[i];
        if(sum1>sum)
        {
            cout<<n-i;
            return 0;
        }
    }
}*/
int strToInt(string s)
{
    int n;
    istringstream ss(s);
    ss >> n;
    return n;
}
vector<int>c;
int main()
{
    c.push_back(47);
    c.push_back(4);
    c.push_back(7);
    c.push_back(44);
    c.push_back(74);
    c.push_back(77);
    int a;
    cin>>a;
    for(int i=0;i<2;i++)
        for(int i1=0;i1<2;i1++)
            for(int i2=0;i2<2;i2++)
            {
                string s;
                if(i==0)
                    s=s+"7";
                else
                    s=s+"4";
                if(i1==0)
                    s=s+"7";
                else
                    s=s+"4";
                if(i2==0)
                    s=s+"7";
                else
                    s=s+"4";
                c.push_back(strToInt(s));
            }
    for(int i=0;i<c.size();i++)
    {
        if(a%c[i]==0)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}