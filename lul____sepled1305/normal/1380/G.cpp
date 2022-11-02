/**Type in macbook ;) Ithea is a nice girl.**/
#include<bits/stdc++.h>
using namespace std;
 
const int N = 3e5+10;
const int MOD = 998244353;
int n,i,j,cur;
vector<int> a;
vector<int> ans;
 
int plusi(int a, int b)
{
    long long cur = (0LL+a+b)%MOD;
    if(cur<0) cur+=MOD;
    return (int) cur;
}
 
int multi(int a, int b)
{
    long long cur =(1LL*a*b)%MOD;
    if(cur<0) cur+=MOD;
    return (int) cur;
}
 
int power(int base, int pow)
{
    if(pow==0)
        return 1;
    if(pow==1)
        return base;
    
    int cur = power(base,pow/2);
    cur = multi(cur,cur);
    if(pow%2==1)
        cur = multi(cur,base);
    return cur;
}
 
int inverse(int base)
{
    return power(base,MOD-2);
}
 
struct fenwickTree
{
private:
    int n;
    vector<int> v;
public:
    fenwickTree(int n)
    {
        this -> n = n;
        int i;
        for(i=0;i<n;i++)
            v.push_back(0);
    }
    void add(int idx, int val)
    {
        for(;idx<n;idx = idx|(idx+1))
            v[idx] = plusi(v[idx],val);
    }
    int sum(int r)
    {
        int cur = 0;
        for(;r>=0;r = (r&(r+1)) - 1)
            cur = plusi(v[r],cur);
        return cur;
    }
    void print()
    {
        for(int it: v)
            cout<<it<<" ";
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    for(i=0;i<n;i++)
    {
        int b;
        cin>>b;
        a.push_back(b);
    }
    sort(a.begin(),a.end());
    fenwickTree thisTree(n);
    for(i=0;i<n;i++)
        thisTree.add(i,a[i]);
    ans.push_back(0);
    for(i=1;i<n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j > (i-1)/(n-i) +1 )
                break;
            cur += thisTree.sum(i-(n-i)*(j-1) -1) - thisTree.sum((i-1)-(n-i+1)*(j-1) -1);
            cur%=MOD;
        }
        ans.push_back(cur);
    }
    while(!ans.empty())
    {
        cout<<multi(ans.back(),inverse(n))<<" ";
        ans.pop_back();
    }
    return 0;
}