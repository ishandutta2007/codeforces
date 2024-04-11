#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 110;
char s[maxn];
int ans;
int len;
bool chk2(int x)
{
    char c1 = '0' + x / 10;
    char c2 = '0' + x % 10;
    for(int i = 0 ; i < len - 1 ; i ++) 
        for(int j = i+1 ; j < len ; j ++) 
            if(s[i] == c1 && s[j] == c2)
			{
                ans = x;
                return true;
        	}
        
    
    return false;
}

bool chk3(int x)
{
    char c1 = '0' + x / 100;
    char c2 = '0' + (x % 100) / 10;
    char c3 = '0' + x % 10;
    for(int i = 0 ; i < len - 2 ; i ++) 
        for(int j = i + 1 ; j < len - 1 ; j ++) 
            for(int t = j + 1 ; t < len ; t ++) 
                if(s[i] == c1 && s[j] == c2 && s[t] == c3)
				{
                    ans = x;
                    return true;
                }
    
    
    
    return false;
}
int main()
{
    scanf("%s",s);
    len = strlen(s);
    for(int i = 0 ; i < len ; i ++)
        if(s[i] == '0') 
		{
            printf("YES\n0\n");
            return 0;
        }
    
    for(int i = 0 ; i < len ; i ++) 
        if(s[i] == '8')
		{
            printf("YES\n8\n");
            return 0;
        }
    
    for(int i = 2 ; i <= 12 ; i ++) 
        if(chk2(8*i))
		{
            printf("YES\n%d\n",ans);
            return 0;
        }
    
    for(int i = 13 ; i <= 124 ; i ++)
        if(chk3(8 * i))
		{
            printf("YES\n%d\n",ans);
            return 0;
        }
    
    printf("NO\n");
    return 0;
}