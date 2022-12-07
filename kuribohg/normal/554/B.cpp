#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
string str;
map<string,int> M;
int n,ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>str,ans=max(ans,++M[str]);
    cout<<ans<<endl;
    return 0;
}