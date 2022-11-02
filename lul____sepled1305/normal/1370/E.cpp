#include<bits/stdc++.h>
using namespace std;
int n,i;
string s,t;
int odd = 0, even = 0;

int main()
{
    cin>>n;
    cin>>s>>t;
    for(i=0;i<s.size();i++)
    {
        if(s.at(i) == '1')
            odd++;
        else
            even++;

        if(t.at(i) == '1')
            odd--;
        else
            even--;
    }
    if(odd!=0 || even !=0)
        cout<<-1;
    else
    {
        int maxi[2];
        maxi[0] = 0;
        maxi[1] = 0;
        int ans = 0;
        int prv  = -1;
        int refi;
        stack<int> st;
        for(i=0;i<n;i++)
        {
            if(s.at(i)!=t.at(i))
            {
                refi = s.at(i)-'0';
                if(st.empty())
                {
                    refi = s.at(i)-'0';
                    st.push(s.at(i)-'0');
                    prv = s.at(i)-'0';
                    if(st.size()>maxi[refi])
                        maxi[refi] = st.size();
                }
                else
                {
                    if(s.at(i)-'0'==st.top())
                    {
                        st.push(s.at(i)-'0');
                        if(st.size()>maxi[refi])
                            maxi[refi] = st.size();
                    }
                    else
                        st.pop();
                }
            }
        }
        ans+=maxi[0];
        ans+=maxi[1];
        cout<<ans;

    }
    return 0;
}