#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,k;
    char s[200010];
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    char sub[200010];
    int len=0,op=0,cl=0,er=0;
    for(int i=0 ; i<n ; i++)
    {
        if(i!=0 && sub[len-1]=='(' && s[i]==')' && n-k-2>=er)
        {
            len--;
            er+=2;
        }
        else
        {
            sub[len]=s[i];
            if(s[i]=='(') op++;
            else cl++;
            len++;
        }
        //cout << len;
        if(len==k && op==cl) break;
    }

    for(int i=0; i<k; i++)
        printf("%c",sub[i]);
}