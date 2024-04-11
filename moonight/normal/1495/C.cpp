#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
inline ll rd()
{
	char c=getchar();ll x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
const int N=505;
int n,m;char s[N][N];
int main()
{
    int T=rd();
    while(T--)
    {
        n=rd();m=rd();
        int st;
        rep(i,1,n)scanf("%s",s[i]+1);
        if(n%3==0)st=2;else st=1;
        for(int i=st;i<=n;i+=3)
        {
            rep(j,1,m)s[i][j]='X';
            if(i+3<=n)
            {
                rep(j,1,m)if(s[i+1][j-1]!='X'&&s[i+1][j+1]!='X'&&s[i+2][j-1]!='X'&&s[i+2][j+1]!='X')
                {
                    s[i+1][j]='X';s[i+2][j]='X';break;
                }
            }
        }
        rep(i,1,n)
        {
            rep(j,1,m)putchar(s[i][j]);
            puts("");
        }
    }
    return 0;
}
/*
5
3 3
X.X
...
X.X
4 4
....
.X.X
....
.X.X
5 5
.X...
....X
.X...
.....
X.X.X
1 10
....X.X.X.
2 2
..
..

*/