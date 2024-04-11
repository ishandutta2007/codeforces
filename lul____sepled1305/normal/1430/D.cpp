#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--) {
        int n,i,j,k;
        string s;
        cin>>n>>s;

        vector<int> compress;
        vector<int> suffix;
        int sum = 1;
        for(i=1;i<n;i++) {
            if(s[i] == s[i-1])
                sum++;
            else
                compress.push_back(sum), sum = 1;
        }
        compress.push_back(sum);
        int turn = 0;
        stack<int> st;
        for(i=0;i<compress.size();i++)
        {
            if(compress[i] == 1)
                st.push(i);
            else
            {
                while(compress[i] > 2 && !st.empty())
                {
                    turn++;
                    st.pop();
                    compress[i]--;
                }
                turn++;
            }
        }
        turn+=((st.size())+1)/2;
        cout<<turn<<endl;
    }
}