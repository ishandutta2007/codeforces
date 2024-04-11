#include<bits/stdc++.h>
#define int long long
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define po pop_back
#define YES cout<<"YES\n" 	#define Yes cout<<"Yes\n"
#define NO cout<<"NO\n"		#define No cout<<"No\n"
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
using namespace std;
void solve()
{
	int a,b,c,n;
	string s,ss;
	ss.clear();
	cin>>n>>a>>b>>c>>s;
    int sss=0;
    for(int i=0;i<n;i++)
    {
    	if(s[i]=='R' && b>0)      b--, ss+='P';
        else if(s[i]=='P' && c>0) c--, ss+='S';
        else if(s[i]=='S' && a>0) a--, ss+='R';
        else ss+='N', sss++;
    }
    if(sss > n/2)
	{
       cout<<"NO"<<'\n'; 
	   return;
    }
    for(int i=0;i<n;i++)
    {
       if(ss[i]=='N')
       {
        	if(a>0) a--,ss[i]='R';
			else if(b>0) b--, ss[i]='P';
		    else if(c>0) c--, ss[i]='S';
       }
    }
    cout<<"YES"<<'\n';
    cout<<ss<<'\n';
}
signed main()
{
	ios;
	int tt; cin>>tt;
	while(tt--)
	{
		solve();
	} 
	return 0;
}