#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int r=m-1;
    int l=0;
    string b[n];
    for(int i=0;i<n;i++)
    cin>>b[i];
    for(int j=m-1;j>=0;j--)
    for(int i=n-1;i>=0;i--)
    if(b[i][j]=='*')
    {r=j; j=0; break;}
    for(int j=0;j<m;j++)
    for(int i=n-1;i>=0;i--)
    if(b[i][j]=='*')
    {l=j; j=m;break;}
    for(int i=0;i<n;i++)
    {
        string c=b[i].substr(l,r-l+1);
        b[i]=c;
    }
    int u=0,d=m-1;
    for(int j=0;j<n;j++)
    for(int i=0;i<m;i++)
    if(b[j][i]=='*')
    {u=j; j=n;break;}
    for(int j=n-1;j>=0;j--)
    for(int i=0;i<m;i++)
    if(b[j][i]=='*')
    {d=j; j=0;break;}
    for(int i=u;i<=d;i++)
    {
		cout<<b[i]<<endl;
	}
}