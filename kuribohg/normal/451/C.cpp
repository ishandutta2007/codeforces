#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int T;
long long n,k,a,b,w1,w2,w3,m;
int main()
{
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%I64d%I64d%I64d%I64d",&n,&k,&a,&b);
        if((k-a-2*b)%3==0)
        {
            w3=(k-a-2*b)/3,w2=w3+b,w1=w2+a;
            m=max(max(w1,w2),w3);
            if(w1>=0&&w2>=0&&w3>=0&&3*m-w1-w2-w3<=n-k&&(n-k-(3*m-w1-w2-w3))%3==0) {puts("yes");continue;}
        }
        if((k-a+2*b)%3==0)
        {
            w3=(k-a+2*b)/3,w2=w3-b,w1=w2+a;
            m=max(max(w1,w2),w3);
            if(w1>=0&&w2>=0&&w3>=0&&3*m-w1-w2-w3<=n-k&&(n-k-(3*m-w1-w2-w3))%3==0) {puts("yes");continue;}
        }
        if((k+a-2*b)%3==0)
        {
            w3=(k+a-2*b)/3,w2=w3+b,w1=w2-a;
            m=max(max(w1,w2),w3);
            if(w1>=0&&w2>=0&&w3>=0&&3*m-w1-w2-w3<=n-k&&(n-k-(3*m-w1-w2-w3))%3==0) {puts("yes");continue;}
        }
        if((k+a+2*b)%3==0)
        {
            w3=(k+a+2*b)/3,w2=w3-b,w1=w2-a;
            m=max(max(w1,w2),w3);
            if(w1>=0&&w2>=0&&w3>=0&&3*m-w1-w2-w3<=n-k&&(n-k-(3*m-w1-w2-w3))%3==0) {puts("yes");continue;}
        }
        puts("no");
    }
    return 0;
}