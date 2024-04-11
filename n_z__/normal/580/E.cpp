#include<bits/stdc++.h>
using namespace std;
char s[100001];
main(){
    int n,m,k;
    cin>>n>>m>>k;
    scanf("%s",s+1);
    m+=k;
    while(m--)
    {
        int f,l,r,c;
        cin>>f>>l>>r>>c;
        if(f==1)memset(s+l,c+'0',r-l+1);
        else puts(memcmp(s+l,s+l+c,r-l-c+1)?"NO":"YES");
    }
}