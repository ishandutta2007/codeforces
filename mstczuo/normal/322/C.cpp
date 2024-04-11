# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;
typedef long long lint;

char s[120]; bool flag=false;
long long tx, ty, cx, cy;

lint Div(lint a,lint b)
{
    if (!b)
        return a?-2:-1;
    if(a*b<0)return -2;
    return (a%b)? -2 : a/b;
}

void solve()
{
    if (flag) return;
    lint a = Div(tx, cx);
    lint b = Div(ty, cy);
    if(a==-2 || b==-2) return;
    if(a==-1 || b==-1)
        flag = true;
    if(a==b)
        flag = true;
}

int main()
{
    cin >> tx >> ty; 
    cx = cy = 0;
    scanf("%s",s); int n = strlen(s);
    for(int i=0; i<n; i++)
        switch(s[i]){
            case 'U': cy++; break;
            case 'D': cy--; break;
            case 'R': cx++; break;
            case 'L': cx--; break;
        }
    
    for(int i=0; i<n; i++){
        solve();
        switch(s[i]){
            case 'U': ty--; break;
            case 'D': ty++; break;
            case 'R': tx--; break;
            case 'L': tx++; break;
        }
    }
    if(flag)printf("Yes\n");
    else printf("No\n");
    return 0;
}