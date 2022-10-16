#include<bits/stdc++.h>
inline int Read()
{
    register int Return,Flag;
    Return=0,Flag=1;
    register char C;
    C=getchar();
    while(!isdigit(C))
    {
        if(C=='-')
        {
            Flag=-1;
        }
        C=getchar();
    }
    while(isdigit(C))
    {
        Return=(Return<<1)+(Return<<3)+(C^'0');
        C=getchar(); 
    }
    return Return*Flag;
}
using namespace std;
int a[1000001];
int main(){
    int ans=0,x=Read();
	for(;x--;)
    {int y=Read();while(y==a[ans])ans--,y++;
    ans++,a[ans]=y;}
	cout<<ans<<endl;
	for(int x=1;x<=ans;x++)
    cout<<a[x]<<' ';
}