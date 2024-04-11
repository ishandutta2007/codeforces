#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n,k;
string s;
bool matched[nmax];
stack<int> unmatch,st;
string now="";
bool good[nmax];

int main()
{
cin>>n>>k>>s;
for(int i=0;i<n;i++)
{
    if(s[i]=='(')unmatch.push(i);
    else
    {
        if(unmatch.size())
        {
            matched[i]=1;
            matched[unmatch.top()]=1;
            unmatch.pop();
        }
    }
}
for(int i=0;i<n;i++)
    if(matched[i])
    now.push_back(s[i]);

assert(now.size()>=k);
int SZ=now.size(),in=now.size();
for(int i=0;i<SZ;i++)
{
    if(in==k)
    {
        st.push(i);
        continue;
    }
    if(now[i]=='(')st.push(i);
    else
    {
        if(st.size()&&now[st.top()]=='(')
        {
            st.pop();
            in=in-2;
        }
        else st.push(i);
    }
}
for(int i=0;i<k;i++)
{
    good[st.top()]=1;
    st.pop();
}
for(int i=0;i<n;i++)
    if(good[i])cout<<s[i];cout<<endl;
return 0;
}