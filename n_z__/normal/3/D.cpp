#include<bits/stdc++.h>
using namespace std;
#define int long long
set<pair<int,int>>st;
main()
{
	string s;
	cin>>s;
	int l=0,r=0;
	for(int x=0;x<s.size();x++)
	{
	    if(s[x]=='(')l++;
	    else if(s[x]==')')l--;
	    else{
	        int u,v;
	        cin>>u>>v;
	        l--;
	        s[x]=')';
	        r+=v;
	        st.insert({u-v,x});
	    }
	    while(l<0&&st.size())
	    {
	        l+=2;
	        s[(*st.begin()).second]='(';
	        r+=(*st.begin()).first;
	        st.erase(st.begin());
	    }
	    if(l<0)break;
	}
	if(l==0)cout<<r<<endl<<s;
	else cout<<-1<<endl;
}