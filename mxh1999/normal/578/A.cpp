#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &digit)
{
    digit=0;
    char c;
    for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
    bool type=false;
    if (c=='-')
        type=true,c=getchar();
    for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
    if (type==true)
        digit=-digit;
}

int a,b;
int main()
{
    read(a),read(b);
    if (a<b)
    {
        printf("-1\n");
        return 0;
    }
    if (a==b)
    {
        printf("%d\n",b);
        return 0;
    }
    a-=b;
    double q,ans,ans1;
    int sum;
    sum=a/b;
    if (sum&1)  sum--;
    if (sum==0) ans=-1;else ans=(double)a/sum;
    a+=2*b;
    sum=a/b;
    if (sum&1)  sum--;
    if (sum==0) ans1=-1;else    ans1=(double)a/sum;
    if  (ans<0||(ans1<ans && ans1>0))   ans=ans1;
    if (ans<0)  printf("-1\n");else printf("%.10lf\n",ans);
    return 0;
}