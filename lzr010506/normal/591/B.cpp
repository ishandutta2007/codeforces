#include <bits/stdc++.h>
using namespace std;
char str[200005],change[30];  
  
int main()
{  
    int n,m;  
    while(~scanf("%d%d",&n,&m))
    {  
        scanf("%s",str);  
        char x,y,tmp;  
        for(int i = 0; i < 26; i ++)  
            change[i] = i + 'a';  
        for(int i = 0; i < m; i ++)
        {  
            getchar();  
            scanf("%c%c%c",&x,&tmp,&y);  
            for(int j = 0; j < 26; j ++) 
                if(change[j] == x) change[j] = y;  
                else if(change[j] == y) change[j] = x;  
        }  
        for(int i = 0; i < n; i ++)  
            str[i] = change[str[i]-'a'];  
        printf("%s\n",str);  
    }  
    return 0;  
}