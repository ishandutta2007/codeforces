#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<utility>
#include<iterator>
using namespace std;
map<string,string> M;
int n,m;
string str1,str2,str;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>str1>>str2;
        if(str2.length()<str1.length()) M.insert(make_pair(str1,str2));
        else M.insert(make_pair(str2,str1));
    }
    for(int i=1;i<=n;i++)
    {
        cin>>str;
        if(M.count(str)) cout<<M[str]<<" ";
        else cout<<str<<" ";
    }
    cout<<endl;
    return 0;
}