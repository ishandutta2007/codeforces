#include<bits/stdc++.h>
using namespace std;
void reduce(string &s,string &t)
{
    while(s.back()==t.back())
    {
        s.pop_back();
        t.pop_back();
    }
}
bool test(string s,string t)
{
    s.erase(0,1);
    t.pop_back();
    return s==t;
}
int main()
{
int n;
string s,t;
cin>>n;
cin>>s>>t;
reduce(s,t);

reverse(s.begin(),s.end());
reverse(t.begin(),t.end());
reduce(s,t);

reverse(s.begin(),s.end());
reverse(t.begin(),t.end());

//cout<<s<<" "<<t<<endl;

if(s.size()==1&&t.size()==1)
{
    printf("2\n");
    return 0;
}

if(test(s,t)&&test(t,s))
{
    printf("2\n");
    return 0;
}

if(test(s,t)||test(t,s))
{
    printf("1\n");
    return 0;
}
    printf("0\n");
    return 0;
return 0;
}