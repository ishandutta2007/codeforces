# include <iostream>
# include <cstdio>
# include <cmath>
using namespace std;

int n,v,s=0,minabs=1001,xcnt=0;

int min(int i,int j)
{
    return i<j?i:j;
}

int main()
{
    scanf("%d",&n);
    int t=n;
    n=(n<<1)-1;
    for(int i=0;i<n;i++){
        scanf("%d",&v);
        s+=abs(v);
        if(v<0)xcnt++;
        minabs=min(minabs,abs(v));
    }
    if(xcnt&1 && !(t&1))
        printf("%d\n",s-minabs*2);
    else
        printf("%d\n",s);
    return 0;
}