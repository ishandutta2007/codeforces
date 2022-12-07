#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
using namespace std;
int n;
map<string,int> M;
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        char op[10],str[30];
        scanf("%s%s",op,str);
        int len=strlen(str);
        reverse(str,str+len);
        for(int i=len+1;i<=18;i++)
            str[len]='0',len++;
        str[len]=0;
        for(int i=0;i<len;i++)
            if((str[i]-'0')&1) str[i]='1';
            else str[i]='0';
        string S(str);
        if(op[0]=='+') M[S]++;
        else if(op[0]=='-') M[S]--;
        else
        {
            if(M.count(S)) printf("%d\n",M[S]);
            else puts("0");
        }
    }
    return 0;
}