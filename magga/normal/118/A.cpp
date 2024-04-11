#include<bits/stdc++.h>
using namespace std;
void solve()
{   //A = 65 a= 97
    string s;cin>>s;
    string ans="";
    for(long long int i=0;i<s.size();i++){
        if(s[i]=='a'||
        s[i]=='e'||
        s[i]=='i'||
        s[i]=='o'||
        s[i]=='u'||
        s[i]=='y'||
        s[i]=='A'||
        s[i]=='E'||
        s[i]=='I'||
        s[i]=='O'||
        s[i]=='U'||
        s[i]=='Y'
        ){
            
        }else{
            ans+='.';
            if(int(s[i])<97){
                ans+=char(97+int(s[i])-65);
            }else{
                ans+=s[i];
            }
        }
    }
    cout<<ans<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num=1;
    //cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }
}