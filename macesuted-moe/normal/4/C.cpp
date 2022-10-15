#include<bits/stdc++.h>
using namespace std; 
map <string,long long> m;
int main(){
    string s;
    long long nCount,i; 
    cin>>nCount;
    getline(cin,s);
    for(i=1;i<=nCount;++i)
	{
        getline(cin,s);
        if(m[s]!=0)
		{
            cout<<s<<m[s]<<'\n';
            ++m[s];
        }
        else
		{
            cout<<"OK\n";
            m[s]=1;
        }
    }
}