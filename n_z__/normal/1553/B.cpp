#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
main()
{
    //ios::sync_with_stdio(false),cin.tie(),cout.tie();
	int q;
	cin>>q;
	while(q--)
	{
        string s,t;
		cin>>s>>t;
		int l1=s.size(),l2=t.size();
		string u=t;
		reverse(u.begin(),u.end());
		s=' '+s,t=' '+t,u=' '+u;
		for(int x=1;x<=l2;x++)
		if(x<=(l2+1)/2){
			string op;
			for(int y=1;y<=x;y++)
			if(t[y]!=t[2*x-y])goto nxt;
			op=t.substr(x,l2-x+1);
			reverse(op.begin(),op.end());
			//cerr<<x<<':'<<op<<endl;
			if(s.find(op)!=string::npos){puts("YES");goto nxxt;}
			nxt:;
		}
		else{
			string op;
			int z=l2-x+1;
			for(int y=1;y<=z;y++)
			if(u[y]!=u[2*z-y])goto nxxxt;
			op=u.substr(z,l2-z+1);
			reverse(op.begin(),op.end());
			//cerr<<x<<':'<<op<<endl;
			if(s.find(op)!=string::npos){puts("YES");goto nxxt;}
			nxxxt:;
		}
		puts("NO");
		nxxt:;
    }
}