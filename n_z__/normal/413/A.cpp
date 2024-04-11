#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,mi,ma;
    cin>>n>>m>>mi>>ma;
    int nmi=1000000,nma=0;
    for(int x=1,y;x<=m;x++)
    cin>>y,nmi=min(nmi,y),nma=max(nma,y);
    if(nmi<mi||nma>ma)cout<<"Incorrect";
    else if(nmi==mi&&nma==ma)cout<<"Correct";
    else if((nmi==mi||nma==ma)&&(n-m>=1))cout<<"Correct";
    else if(n-m>=2)cout<<"Correct";
    else cout<<"Incorrect";
}