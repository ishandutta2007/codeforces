# include <iostream>
# include <cstdio>
using namespace std;

int a,b,c,n,m;

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++){
        scanf("%d",&c);
        if(c==1)a++;
        else b++;
    }
    n=min(a,b)<<1;
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        c=b-a+1;
        if(c&1||c>n)printf("0\n");
        else printf("1\n");
    }
    return 0;
}