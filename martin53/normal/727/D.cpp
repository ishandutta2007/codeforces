#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n;
string inp[nmax];
string output[nmax];
int t[10];
void no()
{
    cout<<"NO"<<endl;
    exit(0);
}
string str[6]={"S", "M", "L", "XL", "XXL", "XXXL"};
int take(string s)
{
    string q="";
    for(auto k:s)
        if(k==',')break;
        else q.push_back(k);
    for(int j=0;j<6;j++)
        if(q==str[j])return j;
    assert(0==1);
}
vector< int > seen;
bool cmp(int x,int y)
{
    return take(inp[x])<take(inp[y]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    for(int i=0;i<6;i++)cin>>t[i];
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>inp[i];
        if(inp[i].find(",")==-1)
        {
            int val=take(inp[i]);
            if(t[val]==0)no();
            t[val]--;
            output[i]=inp[i];
        }
        else seen.push_back(i);
    }
    sort(seen.begin(),seen.end(),cmp);
    for(auto k:seen)
    {
        int val=take(inp[k]);
        if(t[val])
        {
            output[k]=str[val];
            t[val]--;
        }
        else if(t[val+1])
        {
            output[k]=str[val+1];
            t[val+1]--;
        }
        else no();
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
        cout<<output[i]<<endl;
    return 0;
}