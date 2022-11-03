#include <iostream>
#include <cstdio>
using namespace std;
string s;
int s1[105],s2[105],s3[105];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        int len=s.size(),num1=0,num2=0,num3=0;
        for(int i=0;i<len;i++)
            if('0'<=s[i]&&s[i]<='9') s1[++num1]=i;
            else if('a'<=s[i]&&s[i]<='z') s2[++num2]=i;
            else if('A'<=s[i]&&s[i]<='Z') s3[++num3]=i;
        if(num1&&num2&&num3) cout<<s<<endl;
        else if(num1*num2==0&&num2*num3==0&&num1*num3==0)
        {
            if(num1>0) s[0]='a',s[1]='A';
            else if(num2>0) s[0]='0',s[1]='A';
            else s[0]='0',s[1]='a';
            cout<<s<<endl;
        }
        else
        {
            if(num1==0) {if(num2>num3) s[s2[1]]='0'; else s[s3[1]]='0';}
            else if(num2==0) {if(num1>num3) s[s1[1]]='a'; else s[s3[1]]='a';}
            else {if(num1>num2) s[s1[1]]='A'; else s[s2[1]]='A';}
            cout<<s<<endl;
        }
    }
    return 0;
}