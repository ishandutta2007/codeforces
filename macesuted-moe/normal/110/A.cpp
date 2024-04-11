#include<bits/stdc++.h>
using namespace std;
int ans=0;
int main()
{
	string st;
    cin>>st;
    for(int i=0;i<st.size();i++)
        if (st[i]=='4'||st[i]=='7') ans++;
    if (ans==4||ans==7) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return  0;
}